//
// Created by 倪泽溥 on 2022/3/28.
//
#include "../head.h"


class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int pre2 = 0, pre1 = nums[0], cur;
        for (int i = 1; i < n; ++i) {
            cur = max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution solution;
    cout << solution.rob(nums);
}