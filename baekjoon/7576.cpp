#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

#define MAX 1001
#define RIPE 1
#define UNRIPE 0
#define EMPTY -1

int M, N, day = 0;
int Tmatrix[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

deque<vector<int>> startPoint;
vector<vector<int>> moveDirection = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(){
    while (startPoint.size() > 0)
    {
        int x = startPoint.front().front();
        int y = startPoint.front().back();
        startPoint.pop_front();
        visited[x][y] = true;
        for (auto& m: moveDirection)
        {
            int ux = x + m[0];
            int uy = y + m[1];
            if (ux < 0 | ux >= N | uy < 0 | uy >= M)
            {
                continue;
            }
            if (Tmatrix[ux][uy] == EMPTY | Tmatrix[ux][uy] == RIPE | visited[ux][uy] == true)
            {
                continue;
            }
            dist[ux][uy] = dist[x][y] + 1;
            visited[ux][uy] = true;
            day = max(day, dist[ux][uy]);
            startPoint.push_back({ux, uy});
        }

    }
}

int main(){
    /*
    1. 다 탐색하면서 0이면 1로 바꾸기
    2. 순회할 때 마다 cnt를 1씩 더해주기
    3. 전부 순회하면서 0인 경우가 있으면 -1 출력
    4. 양쪽에서 접근하는 경우 처리 ? -> 처음 다 돌면서 1인 경우를 찾자
    4-1. 
    */
    cin >> M >> N;
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> Tmatrix[i][j];
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Tmatrix[i][j] == 1)
            {
                startPoint.push_back({i, j});
            }
        }
    }
    if (startPoint.size() == N * M)
    {
        cout << 0;
        return 0;
    }
    
    bfs();
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (visited[i][j] == false && Tmatrix[i][j] == UNRIPE)
            {
                cout << -1;
                return 0;
            }
            
        }
        
    }
    cout << day;
    return 0;
}