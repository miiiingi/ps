#include <iostream>
#include <vector>
#include <map>

int main()
{
    int K, direction, length;
    std::cin >> K;
    std::vector<std::pair<int, int>> move;
    std::map<int, int> directionCount;
    int bigArea = 1;
    int smallArea = 1;

    for (int i = 0; i < 6; i++)
    {
        std::cin >> direction >> length;
        directionCount[direction - 1]++;
        move.push_back({direction, length});
    }

    for (int i = 0; i < 6; i++)
    {
        if (directionCount[move[i].first - 1] == 1)
        {
            bigArea *= move[i].second;
            smallArea *= move[(i + 3) % 6].second;
        }
    }
    std::cout << (bigArea - smallArea) * K;

    return 0;
}