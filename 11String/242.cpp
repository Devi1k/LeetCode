//
// Created by 倪泽溥 on 2022/4/19.
//
#include "../head.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> res(26, 0);
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); ++i) {
            ++res[s[i] - 'a'];
            --res[t[i] - 'a'];
        }
        for (auto num: res) {
            if (num)
                return false;
        }
        return true;
    }
};