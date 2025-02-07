#include <iostream>
#include <vector>
#include <string>

void dfs(int i, int j, std::vector<std::vector<char>> &map){
    if(i < 0 || i >= map.size() || j < 0 || j >= map[0].size() || map[i][j] == '.'){
        return;
    }
    map[i][j] = '.';
    dfs(i-1, j, map);
    dfs(i+1, j, map);
    dfs(i, j-1, map);
    dfs(i, j+1, map);
}

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int W, H;
        std::cin >> H >> W;
        std::vector<std::vector<char>> map(H, std::vector<char>(W));
        for (int i = 0; i < H; i++)
        {
            std::string line;
            std::cin >> line;
            for (size_t j = 0; j < line.size(); j++)
            {
                map[i][j] = line[j];
            }
        }

        int count = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (map[i][j] == '.')
                {
                    continue;
                }
                dfs(i, j, map);
                count++;
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}