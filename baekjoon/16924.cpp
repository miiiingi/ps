#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define pii pair<int, int>

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    vector<string> cross(N);
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        board[i] = temp;
        cross[i] = temp;
    }

    vector<pii> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, pii>> answer;
    for (size_t i = 0; i < cross.size(); i++)
    {
        for (size_t j = 0; j < cross[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            int y = i;
            int x = j;

            int m = 1;
            bool isFin = false;
            pii check = make_pair(-1, -1);
            while (true)
            {
                for (size_t k = 0; k < direction.size(); k++)
                {
                    int dy = y + direction[k].first * m;
                    int dx = x + direction[k].second * m;
                    if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] != '*')
                    {
                        isFin = true;
                        break;
                    }
                }
                if (isFin)
                {
                    break;
                }
                check.first = y + 1;
                check.second = x + 1;
                cross[y][x] = '.';
                for (size_t k = 0; k < direction.size(); k++)
                {
                    int dy = y + direction[k].first * m;
                    int dx = x + direction[k].second * m;
                    cross[dy][dx] = '.';
                }

                m += 1;
            }
            if (check.first != -1 && check.second != -1)
            {
                answer.push_back(make_pair(m - 1, check));
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (cross[i][j] != '.')
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer.size() << "\n";
    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << answer[i].second.first << " " << answer[i].second.second << " " << answer[i].first << "\n";
    }

    return 0;
}