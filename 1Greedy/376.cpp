//
// Created by 倪泽溥 on 2022/6/19.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.empty()) return 0;
        int curDiff = 0, preDiff = 0, res = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curDiff = nums[i + 1] - nums[i];
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                ++res;
                preDiff = curDiff;
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    Solution solution;
    cout << solution.wiggleMaxLength(nums);
}
