//
// Created by 倪泽溥 on 2022/3/30.
//

#include "../head.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                // i = n - k ^ 2 用k^2（1种）+i（x种）为dp[n]
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};