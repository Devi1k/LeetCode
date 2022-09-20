//
// Created by 倪泽溥 on 2022/3/4.
//

#include "../head.h"

class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &nums, int first, int len) {
        if (first == len) {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < len; ++i) {
            swap(nums[i], nums[first]);
            backtrack(res, nums, first + 1, len);
            swap(nums[i], nums[first]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, nums.size());
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> res = solution.permute(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
