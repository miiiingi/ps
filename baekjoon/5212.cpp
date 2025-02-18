#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void changeToSea(std::vector<std::string> &iMap, std::vector<std::string> &cMap, int x, int y, std::vector<std::pair<int, int>> &record, std ::vector<std::pair<int, int>> &direction)
{
    int adjacentSea = 0;
    for (int i = 0; i < 4; i++)
    {
        int ux = direction[i].first;
        int uy = direction[i].second;
        int dx = x + ux;
        int dy = y + uy;
        if (dx < 0 || dx >= iMap.size() || dy < 0 || dy >= iMap[0].size())
        {
            continue;
        }
        if (iMap[x][y] == 'X' && iMap[dx][dy] == '.')
        {
            adjacentSea++;
        }
    }
    if (adjacentSea < 3)
    {
        record.push_back({x, y});
    }
    else
    {
        cMap[x][y] = '.';
    }
}

int main()
{
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> iMap;
    std::string extendedRow = "";
    std ::vector<std::pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < C + 2; i++)
    {
        extendedRow += '.';
    }

    iMap.push_back(extendedRow);
    for (int i = 0; i < R; i++)
    {
        std::string temp;
        std::cin >> temp;
        temp = '.' + temp + '.';
        iMap.push_back(temp);
    }
    iMap.push_back(extendedRow);
    std::vector<std::string> cMap = iMap;

    // for (size_t i = 0; i < iMap.size(); i++)
    // {
    //     std::cout << iMap[i] << "\n";
    // }

    std::vector<std::pair<int, int>> record;

    for (int i = 0; i < R + 2; i++)
    {
        for (int j = 0; j < C + 2; j++)
        {
            if (iMap[i][j] == '.')
            {
                continue;
            }
            changeToSea(iMap, cMap, i, j, record, direction);
        }
    }

    int minX = 11, minY = 11;
    int maxX = -1, maxY = -1;
    for (size_t i = 0; i < record.size(); i++)
    {
        int x = record[i].first;
        int y = record[i].second;
        minX = std::min(x, minX);
        maxX = std::max(x, maxX);
        minY = std::min(y, minY);
        maxY = std::max(y, maxY);
    }

    // std::cout << "minX: " << minX << " maxX: " << maxX << " miny: " << minY << " maxY: " << maxY << "\n";

    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            std::cout << cMap[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}