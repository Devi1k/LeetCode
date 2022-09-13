//
// Created by 倪泽溥 on 2022/8/3.
//
#include "iostream"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (true) {
            int sum = getSum(n);
            if (sum == 1) return true;
            else if (set.find(sum) != set.end()) return false;
            else set.insert(sum);
            n = sum;
        }
    }
};