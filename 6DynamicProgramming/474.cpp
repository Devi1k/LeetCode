//
// Created by 倪泽溥 on 2022/4/7.
//
#include "../head.h"

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &s: strs) {
            auto[count0, count1] = count(s);
            for (int i = m; i >= count0; --i) {
                for (int j = n; j >= count1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
                }
            }
        }
        return dp[m][n];
    }

    static pair<int, int> count(const string &s) {
        int count0 = s.length(), count1 = 0;
        for (const char &c: s) {
            if (c == '1') {
                ++count1;
                --count0;
            }
        }
        return make_pair(count0, count1);
    }
};