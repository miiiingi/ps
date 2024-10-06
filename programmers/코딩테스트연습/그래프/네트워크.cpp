#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
bool visited[200];
map<int, vector<int>> network;
void dfs(vector<vector<int>> &computers, int node)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    for (int i = 0; i < network[node].size(); i++)
    {
        dfs(computers, network[node][i]);
    }
}
int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[0].size(); j++)
        {
            if (computers[i][j] == 1)
            {
                network[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i])
        {
            continue;
        }
        dfs(computers, i);
        answer++;
    }
    return answer;
}

int main()
{
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    int n = 3;
    cout << solution(n, computers) << "\n";
}