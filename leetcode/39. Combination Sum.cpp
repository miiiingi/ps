#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> answer;
    vector<int> stack;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return answer;
    }
    void dfs(vector<int>& candidates, int target, size_t start){
        int sum = accumulate(stack.begin(), stack.end(), 0);
        if (sum >= target)
        {
            if (sum == target)
            {
                if (find(answer.begin(), answer.end(), stack) == answer.end())
                {
                    answer.push_back(stack);
                }
            }
            return;
        }
        for (size_t i = start; i < candidates.size(); i++)
        {
            stack.push_back(candidates[i]);
            dfs(candidates, target, i);
            stack.pop_back();
        }
    }
};


int main(){
    vector<int> candidates = {7, 3, 2};
    int target = 18;
    Solution sol;
    vector<vector<int>> answer = sol.combinationSum(candidates, target);
    return 0;
}