//
// Created by 倪泽溥 on 2022/7/3.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int minSubArrayLen(vector<int> &nums, int k) {
        int result = INT32_MAX, start = 0, sum = 0;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= k) {
                int subLength = end - start + 1;
                result = result > subLength ? subLength : result;
                sum -= nums[start++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(nums, 7);
}