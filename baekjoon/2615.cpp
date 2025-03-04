#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int board[19][19];
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cin >> board[i][j];
            // cout << "i: " << i << "j: " << j << "board[i][j]: " << board[i][j] << endl;
        }
    }
    vector<pair<int, pair<int, int>>> answer;
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            int x = j;
            int y = i;
            int color = board[y][x];
            for (size_t k = 0; k < directions.size(); k++)
            {
                int mul = 1;
                int dx = x + directions[k].second * mul;
                int dy = y + directions[k].first * mul;
                int cnt = 1;
                while (true)
                {
                    if (board[dy][dx] != color || dx < 0 || dx >= 19 || dy < 0 || dy >= 19)
                    {
                        break;
                    }
                    mul++;
                    dx = x + directions[k].second * mul;
                    dy = y + directions[k].first * mul;
                    cnt++;
                }
                if (cnt == 5)
                {
                    dx = x + directions[k].second * -1;
                    dy = y + directions[k].first * -1;
                    if (board[dy][dx] == color)
                    {
                        continue;
                    }
                    answer.push_back(make_pair(color, make_pair(y + 1, x + 1)));
                }
            }
        }
    }
    sort(answer.begin(), answer.end(), [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
        return a.second.second < b.second.second;
    });

    if (answer.size() == 0)
    {
        cout << 0;
    }
    else
    {
        cout << answer[0].first << "\n";
        cout << answer[0].second.first << " " << answer[0].second.second;
    }

    return 0;
}