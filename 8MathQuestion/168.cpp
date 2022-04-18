//
// Created by 倪泽溥 on 2022/4/16.
//
#include "../head.h"

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output;
        while (columnNumber) {
            int num = columnNumber % 26 + 1;
            output += num - 1 + 'A';
            columnNumber = (columnNumber - num) / 26;
        }

        reverse(output.begin(), output.end());

        return output;
    }
};

int main() {
    Solution solution;
    solution.convertToTitle(27);
}