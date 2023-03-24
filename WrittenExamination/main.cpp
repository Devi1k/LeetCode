#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i == 0) dp[i][j] = j;
                if (j == 0 && i != 0) dp[i][j] = 1;
            }
        }

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int min_num = INT32_MAX;
                for (int k = 0; k < i; ++k) {
                    if (dp[k][j] < min_num) {
                        min_num = dp[k][j];
                    }
                }
                int del = min_num;
                int insert = dp[i - 1][j];
                int replace = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
                dp[i][j] = min(replace, min(del, insert) + 1);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    string word1, word2;
    cin >> word1;
    cin >> word2;
    cout << solution.minDistance(word1, word2);
}
// 64 位输出请用 printf("%lld")