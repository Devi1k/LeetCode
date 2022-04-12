//
// Created by 倪泽溥 on 2022/4/11.
//
#include "../head.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = pairs.size(), res = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
    vector<vector<int>> pairs = {{2, 3},
                                 {1, 2},
                                 {3, 4}};
    Solution solution;
    cout << solution.findLongestChain(pairs);
}