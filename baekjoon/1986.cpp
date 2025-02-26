#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define pii pair<int, int>

void moveQ(int num, vector<pii> &pos, vector<vector<string>> &board)
{
    vector<pii> directionQ = {make_pair(-1, -1), make_pair(-1, 1), make_pair(1, -1), make_pair(1, 1),
                              make_pair(-1, 0),  make_pair(1, 0),  make_pair(0, -1), make_pair(0, 1)};
    for (int i = 0; i < num; i++)
    {
        int x = pos[i].first;
        int y = pos[i].second;
        board[x][y] = "QQ";
        for (size_t j = 0; j < directionQ.size(); j++)
        {
            int muliply = 1;
            while (true)
            {
                int nx = x + directionQ[j].first * muliply;
                int ny = y + directionQ[j].second * muliply;
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                {
                    break;
                }
                if (board[nx][ny] == "PP" || board[nx][ny] == "KK" || board[nx][ny] == "QQ")
                {
                    break;
                }
                board[nx][ny] = "Q";
                // cout << "x: " << nx << " y: " << ny << "\n";
                muliply++;
            }
        }
    }
}
void moveK(int num, vector<pii> &pos, vector<vector<string>> &board)
{
    vector<pii> directionK = {make_pair(-2, -1), make_pair(-2, 1), make_pair(-1, -2), make_pair(-1, 2),
                              make_pair(1, -2),  make_pair(1, 2),  make_pair(2, -1),  make_pair(2, 1)};
    for (int i = 0; i < num; i++)
    {
        int x = pos[i].first;
        int y = pos[i].second;
        board[x][y] = "KK";
        for (size_t j = 0; j < directionK.size(); j++)
        {
            int nx = x + directionK[j].first;
            int ny = y + directionK[j].second;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == ".")
            {
                board[nx][ny] = "K";
                // cout << "x: " << nx << " y: " << ny << "\n";
            }
        }
    }
}
void moveP(int num, vector<pii> &pos, vector<vector<string>> &board)
{
    for (int i = 0; i < num; i++)
    {
        board[pos[i].first][pos[i].second] = "PP";
        // cout << "x: " << pos[i].first << " y: " << pos[i].second << "\n";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<string>> board(n, vector<string>(m, "."));
    vector<pair<int, vector<pii>>> unit(3);
    int numQ;
    for (int i = 0; i < 3; i++)
    {
        // cout << "=======================" << "\n";
        int temp;
        cin >> temp;
        // cout << "temp: " << temp << "\n";
        int x, y;
        vector<pii> tempVec;
        if (temp > 0)
        {
            for (int j = 0; j < temp; j++)
            {
                cin >> x >> y;
                // cout << "x: " << x - 1 << " y: " << y - 1 << "\n";
                tempVec.push_back(make_pair(x - 1, y - 1));
            }
        }

        unit[i] = make_pair(temp, tempVec);
    }

    for (int i = 2; i >= 0; i--)
    {
        if (unit[i].first <= 0)
        {
            continue;
        }
        if (i == 2)
        {
            // cout << "P" << "\n";
            moveP(unit[i].first, unit[i].second, board);
            // cout << "P" << "\n";
        }
        else if (i == 1)
        {
            // cout << "K" << "\n";
            moveK(unit[i].first, unit[i].second, board);
            // cout << "K" << "\n";
        }
        else
        {
            // cout << "Q" << "\n";
            moveQ(unit[i].first, unit[i].second, board);
            // cout << "Q" << "\n";
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == ".")
            {
                answer++;
            }
        }
    }
    cout << answer << "\n";

    return 0;
}