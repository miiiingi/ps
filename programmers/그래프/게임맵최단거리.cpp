#include <vector>
#include <queue>
using namespace std;

#define MAX 100
#define pii pair<int, int>
int solution(vector<vector<int>> maps)
{
    // initialize
    int dist[MAX][MAX] = {1};
    bool visited[MAX][MAX] = {false};
    vector<pii> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    visited[0][0] = true;
    queue<pii> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (size_t i = 0; i < direction.size(); i++)
        {
            int nx = x + direction[i].first;
            int ny = y + direction[i].second;
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size() || maps[nx][ny] == 0 || visited[nx][ny])
            {
                continue;
            }
            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[maps.size() - 1][maps[0].size() - 1] > 0)
    {
        return dist[maps.size() - 1][maps[0].size() - 1];
    }
    else
    {
        return -1;
    }
}

int main()
{
    solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}});
}