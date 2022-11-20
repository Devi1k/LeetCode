//
// Created by 倪泽溥 on 2022/11/20.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto bill: bills) {
            if (bill == 5)
                ++five;
            if (bill == 10) {
                ++ten;
                if (--five < 0) return false;
            }
            if (bill == 20) {
                if (five > 0 && ten > 0) {
                    ++twenty, --ten, --five;
                } else if (five >= 3) {
                    five -= 3;
                    ++twenty;
                } else
                    return false;
            }
        }
        return true;
    }
};