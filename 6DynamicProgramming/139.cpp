#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            for (auto w: wordDict) {
                int len = w.size();
                if (i > len && s.substr(i - len, len) == w) {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};

int main() {
    string s;
    string t;
    cin >> s;
    vector<string> wordDict;
    for (int i = 0; i < 2; ++i) {
        cin >> t;
        wordDict.push_back(t);
    }
    Solution solution;
    cout << solution.wordBreak(s, wordDict);
}