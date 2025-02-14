#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int maxValue = 0;
    int sInd = 0, eInd = 0;
    while (true)
    {
        if (end >= N)
        {
            break;
        }

        if (arr[end] % 2 != 0)
        {
            end++;
        }
        else
        {
            start = end;
            int cnt = 0;
            int possibleDelete = K;
            while (true)
            {
                if (end >= N)
                {
                    break;
                }

                if (arr[end] % 2 != 0)
                {
                    if (possibleDelete <= 0)
                    {
                        end = start + 1;
                        break;
                    }
                    possibleDelete--;
                    end++;
                }
                else if (arr[end] % 2 == 0)
                {
                    end++;
                    cnt++;
                }
            }
            maxValue = max(maxValue, cnt);
        }
    }
    cout << maxValue;

    return 0;
}
