#include<vector>
#include<queue>
using namespace std;
#define pii pair<int, int>

int solution(vector<vector<int> > maps)
{
    int dist[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dist[i][j] = 1;
        }
    }
    bool visited[100][100] = {false};
    vector<pii> DIRECTION = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    visited[0][0] = true;
    queue<pii> q;
    q.push({0, 0});
        while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + DIRECTION[i].first;
            int nextY = y + DIRECTION[i].second;
            if (nextX < 0 || nextX >= maps.size() || nextY < 0 || nextY >= maps[0].size() || visited[nextX][nextY] || maps[nextX][nextY] == 0)
            {
                continue;
            }
            q.push({nextX, nextY});
            visited[nextX][nextY] = true;
            dist[nextX][nextY] = dist[x][y] + 1;
        }
    }

    if(dist[maps.size()-1][maps[0].size()-1] == 1){
        return -1;
    }
    return dist[maps.size()-1][maps[0].size()-1];
}

int main()
{
    solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}});
}