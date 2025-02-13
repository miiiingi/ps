#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main()
{
    int N, K;
    int maxCoord = -1;
    cin >> N >> K;
    vector<int> iceList(1000001, 0);
    for (int i = 0; i < N; i++)
    {
        int ice, coord;
        cin >> ice >> coord;
        maxCoord = max(coord, maxCoord);
        iceList[coord] = ice;
    }
    long initAnswer = 0;
    for (int i = 0; i <= 2 * K; i++)
    {
        if (i > maxCoord)
        {
            break;
        }

        initAnswer += iceList[i];
    }

    int left = 0;
    long answer = initAnswer;
    for (int right = 2 * K + 1; right <= maxCoord; right++)
    {
        initAnswer += iceList[right];
        initAnswer -= iceList[left];
        answer = max(answer, initAnswer);
        left++;
    }
    cout << answer;

    return 0;
}