//
// Created by 倪泽溥 on 2022/5/15.
//
#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums = {0, 1, 3, 4, 5, 6, 7, 8, 9};
    int target = 8;
    Solution solution;
    cout << solution.missingNumber(nums);
}