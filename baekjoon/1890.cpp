#include <iostream>
#include <vector>

int main()
{
    int N, elem;
    std::cin >> N;
    std::vector<std::vector<int>> arr;
    std::vector<std::vector<long>> dp(N, std::vector<long>(N, 0));
    /**
     * dp문제를 풀 때, 수열을 어떻게 정의할 것인지 먼저 생각하기
     * 2차원 배열의 각 좌표에서는 해당 좌표까지 오는데 가능한 경우의 수를 담으면 됨
     */
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            std::cin >> elem;
            temp.push_back(elem);
        }
        arr.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value = arr[i][j];
            int right = j + value;
            int down = i + value;
            if (dp[i][j] == 0 || (i == N-1 && j == N-1))
            {
                continue;
            }

            if (right < N)
            {
                dp[i][right] += dp[i][j];
            }

            if (down < N)
            {
                dp[down][j] += dp[i][j];
            }
        }
    }

    std::cout << dp[N-1][N-1];

    return 0;
}