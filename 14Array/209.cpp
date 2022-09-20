//
// Created by 倪泽溥 on 2022/7/3.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int minSubArrayLen(vector<int> &nums, int target) {
        int n = nums.size();
        if (n < 1 || n == 1 && nums[0] != target) return 0;
        int start = 0, end = 0, ans = INT32_MAX;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                ++start;
            }
            ++end;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(nums, 7);
}