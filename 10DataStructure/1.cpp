//
// Created by 倪泽溥 on 2022/3/16.
//

#include "../head.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = hash.find(target - nums[i]);
            if (iter != hash.end()) {
                return {iter->second, i};
            }
            hash.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> res = solution.twoSum(nums, target);
    for_each(res.begin(), res.end(), show_num);
}