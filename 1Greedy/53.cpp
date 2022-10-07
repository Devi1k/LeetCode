//
// Created by 倪泽溥 on 2022/10/7.
//
// 局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。
// 全局最优：选取最大“连续和”
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN, count = 0;
        for (auto n: nums) {
            count += n;
            if (count >= result) result = count;
            if (count <= 0) count = 0;
        }
        return result;
    }
};