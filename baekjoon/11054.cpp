#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numList(n);
    vector<int> dpInc(n, 0);
    vector<int> dpDesc(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> numList[i];
    }
    for (int i = 0; i < n; i++)
    {
        dpInc[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (numList[j] < numList[i])
            {
                if (dpInc[j] + 1 > dpInc[i])
                {
                    dpInc[i] = dpInc[j] + 1;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dpDesc[i] = 1;
        for (int j = n - 1; j >= i; j--)
        {
            if (numList[j] < numList[i])
            {
                if (dpDesc[j] + 1 > dpDesc[i])
                {
                    dpDesc[i] = dpDesc[j] + 1;
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (dpInc[i] + dpDesc[i] - 1 > answer)
        {
            answer = dpInc[i] + dpDesc[i] - 1;
        }
    }

    cout << answer;

    return 0;
}