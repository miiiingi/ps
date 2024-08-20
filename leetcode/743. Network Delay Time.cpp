#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define pii pair<int, int>
#define INF 999999
#define MAX 1001
class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
        1. 종료조건을 어떻게 줄 것인가 ? {1, 2}, {2, 1}, 2, 2 인 경우 -> indegrees가 모두 계산되었을 때 어떻게 정답을 계산할 것인가 ? 
        2. 뒤에 더 적은 비용으로 업데이트를 어떻게 해줄 것인가 ? 
        */
        int dist[MAX];
        for (size_t i = 0; i < MAX; i++)
        {
            dist[i] = INF;
        }
        priority_queue<pii, vector<pii>, greater<pii>> queue;
        map<int, vector<pii>> timesMap;
        for (auto time: times)
        {
            timesMap[time[0]].push_back({time[2], time[1]});
        }
        queue.push({0, k});
        dist[k] = 0;
        while (!queue.empty())
        {
            int cost = queue.top().first;
            int node = queue.top().second;
            queue.pop();
            if (dist[node] < cost)
            {
                continue;
            }
            
            for (auto next: timesMap[node])
            {
                int nextCost = cost + next.first;
                int nextNode = next.second;
                if (nextCost < dist[nextNode])
                {
                    dist[nextNode] = nextCost;
                    queue.push({nextCost, nextNode});
                }
            }
        }
        int maxValue = 0;
        for (size_t i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
            {
                return -1;
            }
            maxValue = max(maxValue, dist[i]);
        }
        return maxValue;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    // vector<vector<int>> times = {{1, 2, 1}};
    // int n = 2, k = 1;
    // vector<vector<int>> times = {{1, 2, 1}};
    // int n = 2, k = 2;
    // vector<vector<int>> times = {{1, 2, 1}, {2, 1, 3}};
    // int n = 2, k = 2;
    // vector<vector<int>> times = {{1, 2, 1}, {2, 3, 2}, {1, 3, 2}};
    // int n = 3, k = 1;
    cout << sol.networkDelayTime(times, n, k);
    return 0;
}