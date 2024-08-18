#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> indegrees(n + 1, 0);
        queue<int> queue;
        vector<bool> visited(n + 1, false);
        visited[k] = true;
        map<int, vector<int>> timesMap;
        int maxValue = 0;
        for (auto time: times)
        {
            timesMap[time[0]].push_back(time[1]);
            indegrees[time[1]] = time[2];
        }
        queue.push(k);
        while (!queue.empty())
        {
            int qPop = queue.front();
            queue.pop();
            for (auto next: timesMap[qPop])
            {
                indegrees[next] += indegrees[qPop];
                visited[next] = true;
                queue.push(next);
            }
        }
        
        for (auto time: times)
        {
            if (visited[time[1]] == true)
            {
                maxValue = min(time[2], indegrees[time[1]]);
            }
            indegrees[time[1]] = indegrees[time[0]] + time[2];
            maxValue = max(maxValue, indegrees[time[1]]);
        }
        for (size_t i = 1; i <= n; i++)
        {
            if (i == k)
            {
                continue;
            }
            if (indegrees[i] == 0)
            {
                return -1;
            }
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