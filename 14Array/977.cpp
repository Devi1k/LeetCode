//
// Created by 倪泽溥 on 2022/7/2.
//
#include "vector"
#include "iostream"
#include "../head.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> res(nums.size());
        int right = nums.size() - 1, left = 0, len = nums.size() - 1;
        while (left <= right) {
            if (nums[left] * nums[left] >= nums[right] * nums[right]) {
                res[len--] = nums[left] * nums[left];
                ++left;
            } else {
                res[len--] = nums[right] * nums[right];
                --right;
            }
        }
        return res;

    }
};

int main() {
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = solution.sortedSquares(nums);
    for (auto &x: res) {
        cout << x << " ";
    }
}