//
// Created by 倪泽溥 on 2022/4/12.
//
#include "../head.h"


class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
//        vector<vector<int>> dp(n + 1, vector<int>(2));
//        // 0 :手里未持有股票 1：手中持有股票
//        dp[0][0] = 0, dp[0][1] = -prices[0];
//        for (int i = 1; i < n; ++i) {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//        }
//        return dp[n - 1][0];


        int sell = 0, buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            tie(sell, buy) = pair(max(sell, buy + prices[i] - fee), max(buy, sell - prices[i]));
        }
        return sell;
    }
};