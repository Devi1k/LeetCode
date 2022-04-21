//
// Created by 倪泽溥 on 2022/3/23.
//

#include "../head.h"

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        unordered_map<int, vector<int>> hash;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (hash.count(nums[i])) {
                hash[nums[i]][0]++;
                hash[nums[i]][2] = i;
            } else {
                hash[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto &[_, vec]: hash) {
            if (maxNum < vec[0]) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if (maxNum == vec[0]) {
                if (minLen > vec[2] - vec[1] + 1) {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 3, 1};
    Solution solution;
    cout << solution.findShortestSubArray(nums);
}