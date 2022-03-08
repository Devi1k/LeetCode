//
// Created by 倪泽溥 on 2022/3/4.
//
#include "../head.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k, 0);
        int count = 0;
        backtrack(res, comb, count, 1, n, k);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &comb, int &count, int pos, int n, int k) {
        if (count == k) {
            res.emplace_back(comb);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            comb[count++] = i;
            backtrack(res, comb, count, ++i, n, k);
            --count;
        }
    }
};
