//
// Created by 倪泽溥 on 2022/4/7.
//
#include "../head.h"

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2, size = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i < size; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};