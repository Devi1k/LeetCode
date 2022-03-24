//
// Created by 倪泽溥 on 2022/3/22.
//
#include "../head.h"

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> res;
        for (auto &n: nums) {
            if (res.find(n) != res.end())
                return true;
            res.insert(n);
        }
        return false;
    }
};