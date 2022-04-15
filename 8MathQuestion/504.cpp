//
// Created by 倪泽溥 on 2022/4/14.
//
# include "../head.h"

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        bool neg = num < 0;
        if (neg)
            num = -num;
        string ans;
        while (num) {
            int a = num / 7, b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        return neg ? "-" + ans : ans;
    }
};