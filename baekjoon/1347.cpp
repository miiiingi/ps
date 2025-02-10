#include <iostream>
#include <vector>
#include <string>

int changeDirection(int direction, char cmd)
{
    if (cmd == 'R')
    {
        if (direction == 0)
        {
            return 3;
        }
        else if (direction == 1)
        {
            return 0;
        }
        else if (direction == 2)
        {
            return 1;
        }
        else if (direction == 3)
        {
            return 2;
        }
    }
    else
    {
        if (direction == 0)
        {
            return 1;
        }
        else if (direction == 1)
        {
            return 2;
        }
        else if (direction == 2)
        {
            return 3;
        }
        else if (direction == 3)
        {
            return 0;
        }
    }
}

int main()
{
    int N, temp;
    std::cin >> N;
    std::string maze;
    std::vector<std::pair<int, int>> coor;
    std::vector<std::pair<int, int>> direction = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // south, east, north, west
    std::vector<std::vector<char>> mazeMap(101, std::vector<char>(101, '#'));
    std::pair<int, int> baseCoor = std::make_pair(50, 50);
    mazeMap[50][50] = '.';
    int xMax = 50, xMin = 50, yMax = 50, yMin = 50, baseDirection = 0;
    std::cin >> maze;

    for (int i = 0; i < N; i++)
    {
        if (maze[i] == 'F')
        {
            int x = baseCoor.first + direction[baseDirection].first;
            int y = baseCoor.second + direction[baseDirection].second;
            if (x <= 50)
            {
                if (xMin >= x)
                {
                    xMin = x;
                }
            }
            else if (x > 50)
            {
                if (xMax < x)
                {
                    xMax = x;
                }
            }
            if (y <= 50)
            {
                if (yMin >= y)
                {
                    yMin = y;
                }
            }
            else if (y > 50)
            {
                if (yMax < y)
                {
                    yMax = y;
                }
            }

            baseCoor.first = x;
            baseCoor.second = y;
            mazeMap[x][y] = '.';
        }
        else
        {
            baseDirection = changeDirection(baseDirection, maze[i]);
        }
    }
    for (int i = yMax; i >= yMin; i--)
    {
        for (int j = xMin; j <= xMax; j++)
        {
            std::cout << mazeMap[j][i];
        }
        std::cout << "\n";
    }

    return 0;
}