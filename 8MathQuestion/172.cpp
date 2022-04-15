//
// Created by 倪泽溥 on 2022/4/14.
//
#include "../head.h"

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

int main() {
    Solution solution;
    cout << solution.trailingZeroes(20);
}