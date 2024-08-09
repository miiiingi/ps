#include <vector>

using namespace std;

class Solution {
public:
    vector<int> stack;
    vector<vector<int>> answer;

    vector<vector<int>> subsets(vector<int>& nums) {
        for (size_t n = 0; n <= nums.size(); n++)
        {
            dfs(nums, n, 0);
        }
        return answer;
    }
    void dfs(vector<int>& nums, int n, int start){
        if (stack.size() == (size_t)n)
        {
            answer.push_back(stack);
            return;
        }
        for (size_t i = start; i < nums.size(); i++)
        {
            stack.push_back(nums[i]);
            dfs(nums, n, i + 1);
            stack.pop_back();
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer = sol.subsets(nums);
    return 0;
}