//
// Created by 倪泽溥 on 2022/4/10.
//
#include "../head.h"

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
//        int n = nums.size(), maxAns = INT_MIN;
//        vector<int> dp(n, 0);
//        for (int i = 1; i < n; ++i) {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//            maxAns = max(maxAns, dp[i]);
//        }
//        return maxAns;
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(x, pre + x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;

    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    cout << solution.maxSubArray(nums);
}