//
// Created by 倪泽溥 on 2022/10/11.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
    int jump(vector<int> &nums) {
        int cur_distance = 0, next_distance = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            next_distance = max(i + nums[i], next_distance);
            if (i == cur_distance) {
                if (i != nums.size() - 1) {
                    ++res;
                    cur_distance = next_distance;
                    if (cur_distance >= nums.size() - 1)
                        break;
                } else break;
            }
        }
        return res;
    }
};