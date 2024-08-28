#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 3

int matrix[MAX][MAX];
bool visited[MAX][MAX];
bool flag = false;

void dfs(int i, int j)
{
    if (i < 0 || i >= MAX || j < 0 || j >= MAX || matrix[i][j] == 0 || visited[i][j])
    {
        return;
    }
    if (matrix[i][j] == -1)
    {
        flag = true;
        return;
    }
    visited[i][j] = true;
    dfs(i + matrix[i][j], j);
    dfs(i, j + matrix[i][j]);
}
int main()
{
    int N;
    cin >> N;
    memset(matrix, 0, sizeof(matrix));
    memset(visited, false, sizeof(visited));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    dfs(0, 0);
    if (flag)
    {
        cout << "HaruHaru";
    }
    else
    {
        cout << "Hing";
    }

    return 0;
}