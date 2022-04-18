//
// Created by 倪泽溥 on 2022/4/17.
//
#include "../head.h"

class Solution {
public:
    int get_next(int n) {
        int total_num = 0;
        while (n) {
            total_num += (n % 10) * (n % 10);
            n /= 10;
        }
        return total_num;

    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1 && (set.find(n) == set.end())) {
            set.insert(n);
            n = get_next(n);
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    cout << solution.isHappy(2);
}