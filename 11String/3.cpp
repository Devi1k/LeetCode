//
// Created by 倪泽溥 on 2022/4/21.
//
#include "unordered_set"
# include "string"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int r = -1, res = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                set.erase(s[i - 1]);
            }
            while (r + 1 < n && !set.count(s[r + 1])) {
                set.insert(s[i + 1]);
                ++r;
            }
            res = max(res, r - i + 1);
        }
        return res;
    }
};