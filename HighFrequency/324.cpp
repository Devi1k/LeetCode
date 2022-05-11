//
// Created by 倪泽溥 on 2022/5/11.
//

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        int i = 0, j = 0, k = nums.size() - 1;
        while (j < k) {
            if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                --k;
            } else if (nums[j] < mid) {
                swap(nums[j], nums[i]);
                ++i, ++j;
            } else {
                ++j;
            }
        }
        if (nums.size() % 2)
            ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for (int l = 0; l < tmp1.size(); ++l) {
            nums[2 * l] = tmp1[tmp1.size() - 1 - l];
        }
        for (int l = 0; l < tmp2.size(); ++l) {
            nums[2 * l + 1] = tmp2[tmp2.size() - 1 - l];
        }
    }
};