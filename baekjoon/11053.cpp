#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;
    vector<int> num_list(n);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num_list[i];
    }
    for (int i = 0; i < n; i++)
    {
        int maxValue = 0;
        for (int j = 0; j < i; j++)
        {
            if (num_list[j] < num_list[i])
            {
                if (dp[j] > maxValue)
                {
                    maxValue = dp[j];
                }
            }
        }
        dp[i] = maxValue + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > answer)
        {
            answer = dp[i];
        }
    }
    cout << answer;

    return 0;
}