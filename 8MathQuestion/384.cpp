//
// Created by 倪泽溥 on 2022/4/15.
//
#include "../head.h"

class Solution {
    vector<int> origin;

public:
    Solution(vector<int> &nums) : origin(move(nums)) {}


    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {
        if (origin.empty())
            return {};
        vector<int> shuffled(origin);
        int n = origin.size();
        for (int i = n - 1; i >= 0; --i) {
            // 每次i-1 ，需要乱序的数组长度就-1
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        return shuffled;
    }
};

int main() {

    // Your Solution object will be instantiated and called as such:
    Solution *obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();

}