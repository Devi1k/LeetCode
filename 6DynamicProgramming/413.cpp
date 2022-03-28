//
// Created by 倪泽溥 on 2022/3/28.
//
#include "../head.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 7};
    Solution solution;
    cout << solution.numberOfArithmeticSlices(nums);
}