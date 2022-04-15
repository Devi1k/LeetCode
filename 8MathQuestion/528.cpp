//
// Created by 倪泽溥 on 2022/4/15.
//
#include "../head.h"

class Solution {
    vector<int> sums;
public:
    Solution(vector<int> &w) : sums(move(w)) {
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }

    int pickIndex() {
        int pos = (rand() % sums.back()) + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};