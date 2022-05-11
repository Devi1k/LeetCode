//
// Created by 倪泽溥 on 2022/5/10.
//
#include "vector"

using namespace std;

class Solution {
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int res = min(height[l], height[r]) * (r - l);
            ans = max(ans, res);
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return ans;
    }
};