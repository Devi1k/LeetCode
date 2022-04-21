//
// Created by 倪泽溥 on 2022/3/12.
//
#include "../head.h"

class Solution {
public:
    bool isValid(string s) {
        stack<int> parsed;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                parsed.push(s[i]);
            else {
                if (parsed.empty())
                    return false;
                char c = parsed.top();
                if ((s[i] == '}' && c == '{') || (s[i] == ']' && c == '[') || (s[i] == ')' && c == '('))
                    parsed.pop();
                else
                    return false;
            }
        }
        return parsed.empty();
    }
};