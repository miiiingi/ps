#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    int N, start, height;
    int maxHeight = 0, maxIndex = 0, curHeight, curStart;
    long answer = 0;

    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> factory;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> start >> height;
        temp = std::make_pair(start, height);
        factory.push_back(temp);
        if (height > maxHeight)
        {
            maxHeight = height;
        }
    }
    std::sort(factory.begin(), factory.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
              { return a.first < b.first; });

    curStart = factory[0].first;
    curHeight = factory[0].second;

    for (int i = 1; i < N; i++)
    {
        if (factory[i].second >= curHeight)
        {
            answer += curHeight * (factory[i].first - curStart);
            curStart = factory[i].first;
            curHeight = factory[i].second;
        }

        if (factory[i].second == maxHeight)
        {
            maxIndex = i;
            break;
        }
    }

    curStart = factory[N - 1].first;
    curHeight = factory[N - 1].second;

    for (int i = N - 2; i >= maxIndex; i--)
    {
        if (factory[i].second >= curHeight)
        {
            answer += abs(curHeight * (factory[i].first - curStart));
            curStart = factory[i].first;
            curHeight = factory[i].second;
        }
    }
    answer += maxHeight;
    std::cout << answer;

    return 0;
}