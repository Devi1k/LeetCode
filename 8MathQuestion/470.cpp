//
// Created by 倪泽溥 on 2022/4/17.
//
#include "../head.h"

class Solution {
public:

    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = (row - 1) * 7 + col;
        } while (idx > 40);
        return (idx - 1) % 10 + 1;
    }
};

int main() {
    Solution solution;
    cout << solution.rand10();
}