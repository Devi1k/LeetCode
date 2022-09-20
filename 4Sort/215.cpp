//
// Created by 倪泽溥 on 2022/2/28.
//

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int quickSelect(vector<int> &nums, int l, int r, int index) {
        int q = randomPartition(nums, l, r);
        if (q == index) return nums[q];
        else {
            return q < index ? quickSelect(nums, q + 1, r, index) : quickSelect(nums, l, q - 1, index);
        }
    }


    int randomPartition(vector<int> &nums, int l, int r) {
        int x = rand() % (r - l + 1) + l;
        swap(nums[x], nums[r]);
        return partition(nums, l, r);
    }

    int partition(vector<int> &nums, int l, int r) {
        int x = nums[r], i = l - 1;
        for (int j = 0; j < r; ++j) {
            if (nums[j] <= x)
                swap(nums[j], nums[++i]);
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


int main() {
    vector<int> nums = {3, 2, 5, 1, 6, 4};
    int k = 2;
    Solution solution;
    cout << solution.findKthLargest(nums, k);
}