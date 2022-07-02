//
// Created by 倪泽溥 on 2022/3/19.
// [3,4,7,2,-3,1,4,2]
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        int pre = 0, res = 0;
        hash[0] = 1;
        for (auto n: nums) {
            pre += n;
            res += hash[pre - k];
            ++hash[pre];

        }
        return res;
    }
};


