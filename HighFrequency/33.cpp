//
// Created by 倪泽溥 on 2022/5/5.
//
#include "../head.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n < 1) return -1;
        if (n == 1 && nums[0] != target) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target;
    cin >> target;
    Solution solution;
    cout << solution.search(nums, target);
}