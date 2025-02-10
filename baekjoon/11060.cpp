#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N, number, cnt = 0;
    std::vector<int> numList;
    std::queue<int> startPoint;
    std::cin >> N;
    std::vector<int> answer(N + 1, -1);
    startPoint.push(0);
    answer[0] = 0;

    for (int i = 0; i < N; i++)
    {
        std::cin >> number;
        numList.push_back(number);
    }

    while (!startPoint.empty())
    {
        int p = startPoint.front();
        startPoint.pop();
        if (p >= N - 1)
        {
            std::cout << answer[p];
            return 0;
        }

        for (int n = 0; n <= numList[p]; n++)
        {
            int next = p + n;

            if (answer[p + n] == -1)
            {
                startPoint.push(p + n);
                answer[p + n] = answer[p] + 1;
            }
        }
    }
    std::cout << -1;

    return 0;
}