//
// Created by 倪泽溥 on 2022/1/30.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                if (count >= n) {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};


int main() {
    Solution solution;
    vector<int> flowerbed(5,0);
    int n = 2;
    for (int i = 0; i < 5; ++i) {
        int k = 0;
        cin >> k;
        flowerbed[i] = k;
    }

    bool res = solution.canPlaceFlowers(flowerbed, n);
    cout << res;
}

