#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> stack;
    vector<int> stackCopy;
    vector<int> nextStack;
    deque<int> arr;

    vector<vector<int>> combine(int n, int k) {
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        dfs(k, 0);
        return answer;
        
    }
    void dfs(int k, int start){
        if (k == 0)
        {
            answer.push_back(stack);
            return;
        }
        
        for (size_t i = start; i < arr.size(); i++)
        {
            stack.push_back(arr[i]);
            dfs(k-1, i+1);
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