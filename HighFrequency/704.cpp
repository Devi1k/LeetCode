//
// Created by 倪泽溥 on 2022/5/2.
//
#include "../head.h"

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;

    }


};
