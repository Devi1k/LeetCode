//
// Created by 倪泽溥 on 2022/4/8.
//
#include "../head.h"

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }


//    int minSteps(int n) {
//        vector<int> f(n + 1);
//        for (int i = 2; i <= n; ++i) {
//            f[i] = INT_MAX;
//            for (int j = 1; j * j <= i; ++j) {
//                if (i % j == 0) {
//                    f[i] = min(f[i], f[j] + i / j);
//                    f[i] = min(f[i], f[i / j] + j);
//                }
//            }
//        }
//        return f[n];
//    }


};

int main() {
    Solution solution;
    cout << solution.minSteps(8);
}