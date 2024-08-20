#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define pii pair<int, int>
#define MAX 1001
#define INF 10000000001

int main()
{
    int N, M, A, B, cost, start, end;
    map<int, vector<pii>> graph;
    priority_queue<pii, vector<pii>, greater<pii>> queue;
    int dist[MAX];
    for (size_t i = 0; i < MAX; i++)
    {
        dist[i] = INF;
    }

    cin >> N;
    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> A >> B >> cost;
        graph[A].push_back({B, cost});
    }
    cin >> start >> end;
    queue.push({0, start});
    while (!queue.empty())
    {
        int cost = queue.top().first;
        int node = queue.top().second;
        queue.pop();
        if (dist[node] < cost)
        {
            continue;
        }

        for (auto next : graph[node])
        {
            int newCost = cost + next.second;
            int newNode = next.first;
            if (dist[newNode] > newCost)
            {
                dist[newNode] = newCost;
                queue.push({newCost, newNode});
            }
        }
    }
    cout << dist[end];
    return 0;
}
