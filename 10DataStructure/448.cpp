//
// Created by 倪泽溥 on 2022/3/8.
//
#include "../head.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ans;
        for (const auto &num: nums) {
            int pos = abs(num) - 1;
            if (nums[pos] > 0) {
                nums[pos] = -nums[pos];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                ans.emplace_back(i + 1);
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution solution;
    vector<int> ans = solution.findDisappearedNumbers(nums);
    for_each(ans.begin(), ans.end(), show);

}