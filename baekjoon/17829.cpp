#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int pooling(int i, int j, vector<vector<int>> &matrix, vector<pii> &direction)
{
    vector<pair<int, pii>> temp;
    for (int k = 0; k < 4; k++)
    {
        int ux = direction[k].first;
        int uy = direction[k].second;
        int dx = i + ux;
        int dy = j + uy;
        pii directionPair = make_pair(ux, uy);
        temp.push_back(make_pair(matrix[dx][dy], directionPair));
    }
    sort(temp.begin(), temp.end(), [](pair<int, pii> &pa, pair<int, pii> &pb)
         { return pa.first < pb.first; });
    return temp[2].first;
}
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    vector<vector<int>> newMatrix(N / 2, vector<int>(N / 2));
    vector<pair<int, int>> direction = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    while (N != 1)
    {
        vector<vector<int>> newMatrix(N / 2, vector<int>(N / 2));
        for (int i = 0; i < N; i += 2)
        {
            for (int j = 0; j < N; j += 2)
            {
                int value = pooling(i, j, matrix, direction);
                newMatrix[i / 2][j / 2] = value;
            }
        }
        matrix = newMatrix;
        N /= 2;
    }

    cout << matrix[0][0];

    return 0;
}