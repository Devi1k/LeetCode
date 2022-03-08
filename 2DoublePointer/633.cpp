//
// Created by 倪泽溥 on 2022/2/8.
//
#include "math.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = long(sqrt(c));
        while (a <= b) {
            long sum = a * a + b * b;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                a++;
            } else
                b--;
        }
        return false;
    }
};