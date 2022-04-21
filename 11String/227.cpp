//
// Created by 倪泽溥 on 2022/4/21.
//
#include "../head.h"

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.emplace_back(num);
                        break;
                    case '-':
                        stk.emplace_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    case '/':
                        stk.back() /= num;
                        break;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);

    }
};

int main() {
    Solution solution;
    cout << solution.calculate("3 + 5 / 2");
}