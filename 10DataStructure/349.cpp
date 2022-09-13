//
// Created by 倪泽溥 on 2022/8/3.
//
#include "iostream"
#include "unordered_set"
#include "vector"

using namespace std;

class Solution {
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set;
        vector<int> hash(1003, 0);
        for (auto n: nums1) {
            hash[n] = 1;
        }
        for (auto n: nums2) {
            if (hash[n] == 1) {
                set.insert(n);
            }
        }
        return {set.begin(), set.end()};

    }
};