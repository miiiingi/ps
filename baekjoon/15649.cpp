#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<vector<int>> answer;
vector<int> stack;
vector<int> nextStack;
void dfs(vector<int> arr){
    if (stack.size() == static_cast<size_t>(m))
    {
        answer.push_back(stack);
        return;
    }
    for(int a : arr){
        nextStack = arr;
        nextStack.erase(remove(nextStack.begin(), nextStack.end(), a), nextStack.end());
        stack.push_back(a);
        dfs(nextStack);
        stack.pop_back();
    }
}
int main(){
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++)
    {
        arr[i-1] = i;
    }
    dfs(arr);
    for (size_t i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != m - 1)
            {
                cout << answer[i][j] << " ";
            } else {
                cout << answer[i][j] << "\n";
            }
        }
    }
    return 0;
}