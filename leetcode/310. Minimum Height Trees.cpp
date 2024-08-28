#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> answer;
    vector<int> stack;
    vector<int> newStack;
    map<int, vector<int>> graph;
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n <= 1)
        {
            return vector<int>{0};
        }

        for (size_t i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for (size_t i = 0; i < n + 1; i++)
        {
            if (graph[i].size() == 1)
            {
                stack.push_back(i);
            }
        }
        while (n > 2)
        {
            n -= stack.size();
            for (size_t i = 0; i < stack.size(); i++)
            {
                int leaf = graph[stack[i]].back();
                graph[stack[i]].pop_back();
                graph[leaf].erase(find(graph[leaf].begin(), graph[leaf].end(), stack[i]));

                if (graph[leaf].size() == 1)
                {
                    newStack.push_back(leaf);
                }
            }
            stack = newStack;
        }

        return stack;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    sol.findMinHeightTrees(6, edges);
    return 0;
}