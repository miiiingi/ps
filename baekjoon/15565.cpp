#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> numList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numList[i];
    }
    int start = 0, end = 0;
    int lion = 0, cnt = 0;
    int minValue = 10e6;
    while (true)
    {
        if (lion == K)
        {
            minValue = min(minValue, cnt);
            if (numList[start++] == 1)
            {
                lion--;
            }

            if (start >= N)
            {
                break;
            }

            cnt--;
        }
        else
        {
            cnt++;
            if (numList[end++] == 1)
            {
                lion++;
                continue;
            }
            if (end >= N)
            {
                break;
            }
        }
    }
    if (minValue < 10e6)
    {
        cout << minValue;
    }
    else
    {
        cout << -1;
    }

    return 0;
}