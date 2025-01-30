#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;
    vector<int> num_list(n);
    /**
     * dp문제를 풀 때, 수열을 어떻게 정의할 것인지 먼저 생각하기
     * 이번 문제에서는 증가하는 수열에서 각 인덱스까지의 최대합이 몇 인지 구해야함
    */
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
        dp[i] = maxValue + num_list[i];
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