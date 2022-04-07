//
// Created by 倪泽溥 on 2022/4/6.
//
#include "../head.h"

class Solution {
public:
    // 0-1
    int knapsack(vector<int> weights, vector<int> values, int N, int W) {
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= N; ++i) {
            int w = weights[i - 1], v = values[i - 1];
            for (int j = w; j <= W; ++j) {
//                if (j >= w) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
//                } else {
//                    dp[i][j] = dp[i - 1][j];
//                }
            }
        }
        return dp[N][W];
    }

//    int knapsack1(vector<int> weights, vector<int> values, int N, int W) {
//        vector<int> dp(W + 1, 0);
//        for (int i = 1; i <= N; ++i) {
//            int w = weights[i - 1], v = values[i - 1];
//            for (int j = W; j >= w; --j) {
//                dp[j] = max(dp[j], dp[j - w] + v);
//            }
//        }
//        return dp[W];
//    }
    int completely_knapsack(vector<int> weights, vector<int> values, int N, int W) {
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= N; ++i) {
            int w = weights[i - 1], v = values[i - 1];
            // key point
            for (int j = w; j <= W; ++j) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
        return dp[W];
    }

};


int main() {
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    Solution solution;
    cout << solution.completely_knapsack(weights, values, 3, 4) << endl;
    cout << solution.knapsack(weights, values, 3, 4);
}