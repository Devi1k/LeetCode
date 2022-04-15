//
// Created by 倪泽溥 on 2022/4/14.
//
#include "../head.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        string output("");
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int onelen = num1.length(), twolen = num2.length();
        if (onelen <= twolen) {
            swap(num1, num2);
            swap(onelen, twolen);
        }
        int addbit = 0;
        for (int i = 0; i < twolen; ++i) {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += to_string(cur_sum % 10);
            addbit = cur_sum > 10 ? 1 : 0;
        }
        for (int i = twolen; i < onelen; ++i) {
            int cur_sum = (num1[i] - '0') + addbit;
            output += to_string(cur_sum % 10);
            addbit = cur_sum > 10 ? 1 : 0;
        }
        if (addbit)
            output += "1";
        reverse(output.begin(), output.end());
        return output;

    }
};