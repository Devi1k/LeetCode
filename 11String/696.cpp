//
// Created by 倪泽溥 on 2022/4/20.
//

#include "../head.h"

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0, n = s.size();
        vector<int> counts;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.emplace_back(count);
        }
        int ans = 0;
        for (int i = 0; i < counts.size() - 1; ++i) {
            ans += min(counts[i], counts[i + 1]);
        }
        return ans;
    }


};