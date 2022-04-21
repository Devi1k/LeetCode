//
// Created by 倪泽溥 on 2022/3/19.
//
#include "../head.h"

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int count = 0, psum = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        for (auto i: nums) {
            psum += i;
            count += hashmap[psum - k];
            ++hashmap[psum];
        }
        return count;
    }
};


int main() {
    vector<int> nums = {1, 1, 1};
    Solution solution;
    cout << solution.subarraySum(nums, 2);
}