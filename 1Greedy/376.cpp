//
// Created by 倪泽溥 on 2022/6/19.
// 局部最优：删除单调坡度上的节点（不包括单调坡度两端的节点），那么这个坡度就可以有两个局部峰值。
// 整体最优：整个序列有最多的局部峰值，从而达到最长摆动序列。
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();
        int result = 1;
        int cur_diff = 0, pre_diff = 0;
        for (int i = 1; i < nums.size(); ++i) {
            cur_diff = nums[i] - nums[i - 1];
            if (cur_diff > 0 && pre_diff <= 0 || cur_diff < 0 && pre_diff >= 0) {
                result++;
                pre_diff = cur_diff;
            }
        }
        return result;
    }
};


int main() {
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    Solution solution;
    cout << solution.wiggleMaxLength(nums);
}
