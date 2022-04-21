//
// Created by 倪泽溥 on 2022/4/21.
//
#include "../head.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;
        vector<int> next(m);
        // 构造next数组
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
                ++j;
            next[i] = j;
        }
        // 进行匹配
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
                ++j;
            if (j == m)
                return i - m + 1;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    cout << solution.strStr("aabaabaaf", "aabaaf");
}