#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define pii pair<int, int>

vector<pii> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bomb(int R, int C, int N, vector<string> &board, vector<vector<int>> &check)
{
    int timer = 2;
    while (1)
    {
        if (timer == N + 1)
        {
            break;
        }
        else if (timer % 2 == 0)
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (board[i][j] == '.')
                    {
                        board[i][j] = 'O';
                        check[i][j] = timer + 3;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if (check[i][j] == timer)
                    {
                        board[i][j] = '.';
                        check[i][j] = -1;
                        for (size_t k = 0; k < direction.size(); k++)
                        {
                            int dy = i + direction[k].first;
                            int dx = j + direction[k].second;
                            if (dx < 0 || dx >= C || dy < 0 || dy >= R)
                            {
                                continue;
                            }
                            board[dy][dx] = '.';
                        }
                    }
                }
            }
        }
        timer++;
    }
}

int main()
{
    int R, C, N;
    cin >> R >> C >> N;
    vector<string> board(R);
    vector<vector<int>> check(R, vector<int>(C, -1));

    for (size_t i = 0; i < R; i++)
    {
        cin >> board[i];
        for (size_t j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                check[i][j] = 3;
            }
        }
    }
    bomb(R, C, N, board, check);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}