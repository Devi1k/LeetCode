//
// Created by 倪泽溥 on 2022/4/14.
//

#include "../head.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 换底公式
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};