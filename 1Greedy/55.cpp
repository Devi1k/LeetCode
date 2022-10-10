//
// Created by 倪泽溥 on 2022/10/10.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int cover = 0;
        if (nums.size() <= 1) return true;
        for (int i = 0; i <= cover; ++i) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};