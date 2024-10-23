#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0]; // 현재 위치에서의 최댓값
        int maxNum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i], dp[i-2]);
            maxNum = max(dp[i], maxNum);
        }
        return maxNum;
    }
};