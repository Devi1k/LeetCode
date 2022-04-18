//
// Created by 倪泽溥 on 2022/4/16.
//
#include "../head.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
//        vector<int> L(n), R(n);
//        L[0] = 1, R[n - 1] = 1;
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            ans[i] = nums[i - 1] * ans[i - 1];
        }
        int R = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }
//        for (int i = 0; i < n; ++i) {
//            ans[i] = L[i] * R[i];
//        }
        return ans;
    }
};