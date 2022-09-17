//
// Created by 倪泽溥 on 2022/4/21.
//
# include "string"
# include "vector"
# include "iostream"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int max_len = 1, begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = len + i - 1;
                if (j >= n) break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max_len);
    }
};


int main() {
    Solution solution;
    cout << solution.longestPalindrome("ababa");
}