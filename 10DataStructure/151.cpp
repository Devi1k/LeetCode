//
// Created by 倪泽溥 on 2022/8/24.
//
# include "string"

using namespace std;

class Solution {
public:
    void remove_extra_space(string &s) {
        int slow_index = 0, fast_index = 0;
        while (s.size() > 0 && fast_index < s.size() && s[fast_index] == ' ') {
            ++fast_index;
        }
        for (; fast_index < s.size(); ++fast_index) {
            if (fast_index - 1 > 0 && s[fast_index] == s[fast_index - 1] && s[fast_index - 1] == ' ') continue;
            else {
                s[slow_index++] = s[fast_index];
            }
        }
        if (slow_index - 1 > 0 && s[slow_index - 1] == ' ') {
            s.resize(slow_index - 1);
        } else {
            s.resize(slow_index);
        }
    }

    void reverse(string &s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }


    string reverseWords(string s) {
        int start = 0;
        remove_extra_space(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};