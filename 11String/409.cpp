//
// Created by 倪泽溥 on 2022/4/21.
//
#include "../head.h"

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (auto c: s) {
            ++count[c];
        }
        for (auto c: count) {
            int v = c.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 && ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};