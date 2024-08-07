#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> stack;
    vector<int> stackCopy;
    vector<int> nextStack;

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        dfs(arr, k, 0);
        return answer;
        
    }
    void dfs(vector<int> arr, int k, int start){
        if (stack.size() == static_cast<size_t>(k))
        {
            stackCopy = stack;
            sort(stackCopy.begin(), stackCopy.end());
            if (find(answer.begin(), answer.end(), stackCopy) == answer.end())
                {
                answer.push_back(stack);
                }
            return;
        }
        for (size_t i = start; i < arr.size(); i++)
        {
            nextStack = arr;
            nextStack.erase(nextStack.begin() + i);
            stack.push_back(arr[i]);
            dfs(nextStack, k, start);
            stack.pop_back();
        }
    }
};

int main(){
    int n = 4, k = 2;
    Solution sol;
    vector<vector<int>> answer = sol.combine(n, k);
    return 0;
}