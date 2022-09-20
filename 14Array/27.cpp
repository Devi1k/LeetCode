//
// Created by 倪泽溥 on 2022/7/1.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int fast = 0, slow = 0;
        for (; fast < nums.size(); ++fast) {
            if (nums[fast] != k) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution solution;
    cout << solution.removeElement(nums, 3);
}