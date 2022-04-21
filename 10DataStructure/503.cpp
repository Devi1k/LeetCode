//
// Created by 倪泽溥 on 2022/3/22.
//

#include "../head.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;

    }
};

int main() {
    vector<int> nums = {1, 2, 1};
    Solution solution;
    vector<int> res = solution.nextGreaterElements(nums);
    for_each(res.begin(), res.end(), show_num);
}