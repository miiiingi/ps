#include <iostream>
#include <vector>

using namespace std;
int N;
#define MAX 10
bool visited[MAX];
int W[MAX][MAX];

void dfs(int startP)
{
}

int main()
{
    cin >> N;
    memset(W, 0, sizeof(W));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(i+1);
    }

    return 0;
}