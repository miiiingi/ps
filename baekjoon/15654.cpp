#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stack;
vector<int> numList;
vector<int> nextStack;
vector<vector<int>> answer;
int N, M;

void dfs(vector<int> numList)
{
    if (stack.size() == static_cast<size_t>(M))
    {
        answer.push_back(stack);
        return;
    }
    for (int num : numList)
    {
        nextStack = numList;
        nextStack.erase(remove(nextStack.begin(), nextStack.end(), num), nextStack.end());
        stack.push_back(num);
        dfs(nextStack);
        stack.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    numList.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numList[i];
    }

    sort(numList.begin(), numList.end());
    dfs(numList);

    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            if (j != answer[i].size() - 1)
            {
                cout << answer[i][j] << " ";
            }
            else
            {
                cout << answer[i][j] << "\n";
            }
        }
    }

    return 0;
}