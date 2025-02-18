#include <iostream>
#include <vector>
#include <string>
#include <cstring>

void dfs(int i, int j, int M, int N, std::vector<std::vector<char>> &fiber)
{
    if (i < 0 || i >= M || j < 0 || j >= N || fiber[i][j] == '1' || fiber[i][j] == 'x')
    {
        return;
    }
    fiber[i][j] = 'x';
    dfs(i - 1, j, M, N, fiber);
    dfs(i + 1, j, M, N, fiber);
    dfs(i, j - 1, M, N, fiber);
    dfs(i, j + 1, M, N, fiber);
}

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::vector<std::vector<char>> fiber(M, std::vector<char>(N));
    for (int i = 0; i < M; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < N; j++)
        {
            fiber[i][j] = (char)str[j];
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (fiber[0][j] == '1' || fiber[0][j] == 'x')
        {
            continue;
        }
        dfs(0, j, M, N, fiber);
    }

    for (size_t i = 0; i < fiber[M - 1].size(); i++)
    {
        if (fiber[M - 1][i] == 'x')
        {
            std::cout << "YES";
            return 0;
        }
    }

    std::cout << "NO";
    return 0;
}