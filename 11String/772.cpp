//
// Created by 倪泽溥 on 2022/4/21.
//
#include "../head.h"

class Solution {
public:
    int findSub(string s, int i) {
        int level = 0;
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '(')
                ++level;
            else if (s[j] == ')')
                if (--level == 0)
                    return j;
        }
        return 0;
    }

    int calculate(string s) {
        vector<int> res;
        char preSign = '+';
        int n = s.size(), num = 0, j;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            if (s[i] == '(') {
                j = findSub(s, i);
                string brackets = s.substr(i + 1, j - i - 1);
                num = calculate(brackets);
                i += j - i + 1;
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        res.emplace_back(num);
                        break;
                    case '-':
                        res.emplace_back(-num);
                        break;
                    case '*':
                        res.back() *= num;
                        break;
                    case '/':
                        res.back() /= num;
                        break;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(res.begin(), res.end(), 0);
    }
};

int main() {
    Solution solution;
    cout << solution.calculate("2*(5+5*2)/3+(6/2+8)");
}