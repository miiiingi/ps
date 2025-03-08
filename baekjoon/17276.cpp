#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int n, d;
        cin >> n >> d;
        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }
        int mid = n / 2;
        for (int i = 0; i < abs(d) / 45; i++)
        {
            vector<vector<int>> check = board;
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    int in = check[j][k];
                    if (d > 0)
                    {
                        if (j == k)
                        {
                            board[j][mid] = in;
                        }
                        else if (k == mid)
                        {
                            board[j][n - j - 1] = in;
                        }
                        else if (j + k == n - 1)
                        {
                            board[mid][k] = in;
                        }
                        else if (j == mid)
                        {
                            board[k][k] = in;
                        }
                    }
                    else
                    {
                        if (j == k)
                        {
                            board[mid][j] = in;
                        }
                        else if (k == mid)
                        {
                            board[j][j] = in;
                        }
                        else if (j + k == n - 1)
                        {
                            board[j][mid] = in;
                        }
                        else if (j == mid)
                        {
                            board[n - 1 - k][k] = in;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        T--;
    }

    return 0;
}