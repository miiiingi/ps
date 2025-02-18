#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int calcCandy(int x, int y, int N, std::vector<std::string> &candyMap)
{
    char type = candyMap[x][y];
    int cntX = 1;
    int maxX = 0;
    for (int i = 1; i < N; i++)
    {
        if (candyMap[i][y] == type && candyMap[i - 1][y] == type)
        {
            cntX++;
            if (maxX < cntX)
            {
                maxX = cntX;
            }
        }
        else
        {
            cntX = 1;
        }
    }
    int cntY = 1;
    int maxY = 0;
    for (int i = 1; i < N; i++)
    {
        if (candyMap[x][i] == type && candyMap[x][i - 1] == type)
        {
            cntY++;
            if (maxY < cntY)
            {
                maxY = cntY;
            }
        }
        else
        {
            cntY = 1;
        }
    }
    if (maxX >= maxY)
    {
        return maxX;
    }
    else
    {
        return maxY;
    }
}
void swap(int x, int y, int dx, int dy, std::vector<std::string> &candyMap)
{
    char temp = candyMap[dx][dy];
    candyMap[dx][dy] = candyMap[x][y];
    candyMap[x][y] = temp;
}
int check(int x, int y, int N, std::vector<std::string> &candyMap)
{
    std::vector<std::pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxCandy = 0;
    for (int d = 0; d < 4; d++)
    {
        int ux = direction[d].first;
        int uy = direction[d].second;
        int dx = x + ux;
        int dy = y + uy;
        if (dx < 0 || dx >= N || dy < 0 || dy >= N)
        {
            continue;
        }
        swap(x, y, dx, dy, candyMap);
        int candy = calcCandy(x, y, N, candyMap);
        swap(x, y, dx, dy, candyMap);
        if (maxCandy < candy)
        {
            maxCandy = candy;
        }
    }
    return maxCandy;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<std::string> candyMap;
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        candyMap.push_back(str);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int candy = check(i, j, N, candyMap);
            if (answer < candy)
            {
                answer = candy;
            }
        }
    }

    std::cout << answer;

    return 0;
}