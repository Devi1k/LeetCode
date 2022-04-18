//
// Created by 倪泽溥 on 2022/4/17.
//
# include "../head.h"

class Solution {
public:


    int parition(vector<int> &nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j <= right; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[right], nums[i]);
        return i;
    }

    int select(vector<int> &nums, int left, int right, int k) {
        if (left == right)
            return nums[left];
        int pivotIndex = parition(nums, left, right);
        if (k == pivotIndex)
            return nums[k];
        else if (k < pivotIndex)
            return select(nums, left, pivotIndex - 1, k);
        else
            return select(nums, pivotIndex + 1, right, k);
    }

    int minMoves2(vector<int> &nums) {
        int sum = 0;
        int medium = select(nums, 0, nums.size() - 1, nums.size() / 2);
        for (auto n: nums) {
            sum += abs(medium - n);
        }
        return sum;
    }
};
