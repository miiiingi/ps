#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int N, M;
    std::cin >> N >> M;
    std::map<int, std::vector<int>> change;
    std::queue<std::pair<int, int>> stack;
    std::vector<int> count(N + 1, 0);
    std::vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int start, end;
        std::cin >> start >> end;
        change[start].push_back(end);
        change[end].push_back(start);
    }

    stack.push(std::make_pair(a, 0));

    while (!stack.empty())
    {
        std::pair<int, int> temp = stack.front();
        visited[temp.first] = true;
        stack.pop();
        if (temp.first == b)
        {
            std::cout << temp.second;
            return 0;
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i] && find(change[temp.first].begin(), change[temp.first].end(), i) != change[temp.first].end())
            {
                visited[i] = true;
                stack.push(std::make_pair(i, temp.second + 1));
            }
        }
    }

    std::cout << -1;
    return 0;
}