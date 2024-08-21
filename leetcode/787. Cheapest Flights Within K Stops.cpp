#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;
#define pii pair<int, pair<int, int>>
#define INF 100000001
#define MAX 101
class Solution
{
public:
    /*
    1. k를 어떻게 관리해줄 것인가?
    2. 진행했는데, 최소 값이 아닌 경우, 어떻게 돌아갈 것인가?(약간 dfs?)
    */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        int dist[MAX];
        for (size_t i = 0; i < MAX; i++)
        {
            dist[i] = INF;
        }
        priority_queue<pii, vector<pii>, greater<pii>> queue;
        map<int, vector<pair<int, int>>> flightsMap;
        for (size_t i = 0; i < flights.size(); i++)
        {
            flightsMap[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue.push({0, {src, k + 1}});
        while (!queue.empty())
        {
            int cost = queue.top().first;
            int node = queue.top().second.first;
            int curK = queue.top().second.second;
            queue.pop();
            if (node == dst)
            {
                return dist[dst];
            }
            if (curK > 0)
            {
                for (auto flight : flightsMap[node])
                {
                    int newCost = cost + flight.second;
                    int newNode = flight.first;
                    dist[newNode] = newCost;
                    queue.push({newCost, {newNode, curK - 1}});
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1);
    return 0;
}