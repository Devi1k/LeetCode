//
// Created by 倪泽溥 on 2022/2/11.
//
#include "vector"

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &nums, int target, bool lower) {
        int l = 0, r = nums.size() - 1, ans = nums.size();
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) -1 ;
        if (leftIdx <= rightIdx && leftIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
            return vector<int>{leftIdx, rightIdx};
        return vector<int>{-1, -1};
    }
};