//
// Created by 倪泽溥 on 2022/4/13.
//
#include "../head.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        vector<int> ways;
        if (n == 1 || n == 2) {
            ways.push_back(stoi(expression));
            return ways;
        }
        for (int i = 0; i < n; ++i) {
            auto c = expression[i];
            if (c == '*' || c == '+' || c == '-') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (auto l: left) {
                    for (auto r: right) {
                        switch (c) {
                            case '+':
                                ways.emplace_back(l + r);
                                break;
                            case '*':
                                ways.emplace_back(l * r);
                                break;
                            case '-':
                                ways.emplace_back(l - r);
                                break;
                        }
                    }
                }
            }
        }
        return ways;
    }
};