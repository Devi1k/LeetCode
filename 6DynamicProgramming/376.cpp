//
// Created by 倪泽溥 on 2022/4/11.
//

#include "../head.h"

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        const int n = nums.size();
        if (n < 2)
            return n;
        vector<int> up(n), down(n);
        up[0] = 1, down[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                down[i] = down[i - 1];
                up[i] = max(up[i - 1], down[i - 1] + 1);
            } else if (nums[i] < nums[i - 1]) {
                down[i] = max(up[i - 1] + 1, down[i - 1]);
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};