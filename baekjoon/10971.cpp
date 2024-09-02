#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, minValue = 10000001;
#define MAX 10
bool visited[MAX];
int W[MAX][MAX];

void dfs(int startP, int curP, int cnt, int sum)
{
    if (cnt == N)
    {
        if (W[curP][startP] == 0)
        {
            return;
        }
        if (minValue > sum + W[curP][startP])
        {
            minValue = sum + W[curP][startP];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] || W[curP][i] == 0)
        {
            continue;
        }
        visited[i] = true;
        dfs(startP, i, cnt + 1, sum + W[curP][i]);
        visited[i] = false;
    }
}

int main()
{
    cin >> N;
    memset(W, 0, sizeof(W));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        visited[i] = true;
        dfs(i, i, 1, 0);
        visited[i] = false;
    }
    cout << minValue;

    return 0;
}