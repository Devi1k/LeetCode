//
// Created by 倪泽溥 on 2022/4/7.
//
#include "../head.h"

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount + 1, amount + 2);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int &coin: coins) {
                if (i >= coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 2 ? -1 : dp[amount];
    }
};


int main() {
    Solution solution;
    vector<int> coins = {2, 5};
    cout << solution.coinChange(coins, 1);
}