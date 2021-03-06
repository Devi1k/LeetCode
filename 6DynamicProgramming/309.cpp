//
// Created by 倪泽溥 on 2022/4/9.
//
#include "../head.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> buy(n), sell(n), s1(n), s2(n);
        s1[0] = buy[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for (int i = 1; i < n; ++i) {
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = max(buy[i - 1], s1[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = max(s2[i - 1], sell[n - 1]);
        }
        return max(sell[n - 1], s2[n - 1]);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << solution.maxProfit(prices);
}