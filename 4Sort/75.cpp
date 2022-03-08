//
// Created by 倪泽溥 on 2022/3/1.
//
#include "../head.h"

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int l = 0, r = nums.size();
        quick_sort(nums, l, r);
    }

    void quick_sort(vector<int> &nums, int l, int r) {
        if (l + 1 >= r)
            return;
        int first = l, last = r - 1, key = nums[first];
        while (first < last) {
            while (first < last && nums[last] >= key) {
                --last;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= key) {
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quick_sort(nums, l, first);
        quick_sort(nums, first + 1, r);
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution solution;
    solution.sortColors(nums);
    for (auto &elem: nums) cout << elem << " ";
    cout << endl << endl;

    return 0;
}
