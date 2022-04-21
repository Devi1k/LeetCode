//
// Created by 倪泽溥 on 2022/4/21.
//
#include "../head.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // Len为子串长度
        for (int Len = 2; Len <= n; ++Len) {
            for (int i = 0; i < n; ++i) {
                int j = Len + i - 1;
                if (j >= n)
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    // 长度为3，最小的回文子串
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                //更新起始位置以及最大长度
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};