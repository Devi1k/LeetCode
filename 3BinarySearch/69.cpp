//
// Created by 倪泽溥 on 2022/2/11.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int mySqrt(int a) {
        if (a == 0)
            return a;
        int l = 0, r = a, mid, ans;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if ((long long) mid * mid <= a) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

//    牛顿迭代
//    int mySqrt(int a) {
//        long x = a;
//        while (x * x > a) {
//            x = (x + a / x) / 2;
//        }
//        return x;
//    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(8);
}