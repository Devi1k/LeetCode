//
// Created by 倪泽溥 on 2022/3/23.
//
#include "../head.h"

class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> hashmap;
        int res = 0;
        for (auto num: nums) {
            ++hashmap[num];
        }
        for (auto[key, val]: hashmap) {
            if (hashmap.count(key + 1))
                res = max(res, hashmap[key + 1] + val);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    Solution solution;
    cout << solution.findLHS(nums);
}