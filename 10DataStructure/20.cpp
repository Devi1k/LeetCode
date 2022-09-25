//
// Created by 倪泽溥 on 2022/3/12.
//
#include "stack"
#include "string"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto str: s) {
            if (str == '(' || str == '{' || str == '[') {
                stack.push(str);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    char c = stack.top();
                    if (str == ')' && c == '(' || str == ']' && c == '[' || str == '}' && c == '{') {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stack.empty();
    }
};