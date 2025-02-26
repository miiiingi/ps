#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, C, W;
    cin >> N >> C >> W;
    vector<int> arr(N);
    int maxtree = 0;
    long long maxValue = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        maxtree = max(maxtree, arr[i]);
    }
    for (int i = 0; i < maxtree; i++)
    {
        int cnt = 0;
        int div = i + 1;
        long long money = 0;
        for (int j = 0; j < N; j++)
        {
            long long tempMoney = 0;
            if (div > arr[j])
            {
                continue;
            }

            cnt = arr[j] / div;
            tempMoney += cnt * div * W;
            if (arr[j] % div == 0)
            {
                tempMoney -= (cnt - 1) * C;
            }
            else
            {
                tempMoney -= cnt * C;
            }
            if (tempMoney < 0)
            {
                continue;
            }
            else
            {
                money += tempMoney;
            }
        }
        cnt = 0;
        maxValue = max(maxValue, money);
    }
    cout << maxValue;

    return 0;
}