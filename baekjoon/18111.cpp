#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int main()
{
    int N, M, B;
    cin >> N >> M >> B;
    vector<vector<int>> landMap(N, vector<int>(M));
    int maxValue = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            landMap[i][j] = temp;
            maxValue = max(maxValue, temp);
        }
    }
    vector<pii> buildV;
    for (int i = 0; i <= maxValue; i++)
    {
        int fcommand = 0;
        int scommand = 0;
        int iB = B;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (i > landMap[j][k])
                {
                    scommand += (i - landMap[j][k]);
                    iB -= (i - landMap[j][k]);
                }
                else if (i < landMap[j][k])
                {
                    fcommand += (landMap[j][k] - i);
                    iB += (landMap[j][k] - i);
                }
            }
        }
        if (iB < 0)
        {
            continue;
        }

        pii temp = make_pair(fcommand * 2 + scommand, i);
        buildV.push_back(temp);
    }

    sort(buildV.begin(), buildV.end(), [](const pii &p1, const pii &p2)
         {
             if (p1.first == p2.first)
             {
                 return p1.second > p2.second;
             }
             return p1.first < p2.first; });
    pii answer = buildV[0];
    cout << answer.first << " " << answer.second;

    return 0;
}
