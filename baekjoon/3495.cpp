#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> board(h);
    for (int i = 0; i < h; i++)
    {
        cin >> board[i];
        // cout << "board[i]: " << board[i] << endl;
    }
    bool isStarted;
    int shapeCnt;
    int answer = 0;
    for (int i = 0; i < h; i++)
    {
        isStarted = false;
        shapeCnt = 0;
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == '.' && !isStarted)
            {
                continue;
            }
            else if (board[i][j] == '.' && isStarted)
            {
                // cout << "i: " << i << " j: " << j << " board[i][j]: " << board[i][j] << endl;
                answer += 2;
            }
            else
            {
                // cout << "i: " << i << " j: " << j << " board[i][j]: " << board[i][j] << endl;
                answer++;
                shapeCnt++;
                if (shapeCnt == 1)
                {
                    isStarted = true;
                }
                else
                {
                    isStarted = false;
                    shapeCnt = 0;
                }
            }
        }
    }
    cout << answer / 2;

    return 0;
}