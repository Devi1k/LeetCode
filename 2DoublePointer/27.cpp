//
// Created by zepu.ni on 2022/8/30.
//
# include "vector"
# include "iostream"

using namespace std;

class Solution {
public:
    int removeElements(vector<int> &nums, int val) {
        if (nums.empty()) return 0;
        int slow_index = 0, fast_index = 0;
        for (; fast_index < nums.size(); ++fast_index) {
            if (nums[fast_index] != val) {
                nums[slow_index++] = nums[fast_index];
            }
        }
        return slow_index;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    cout << solution.removeElements(nums, 3);
}