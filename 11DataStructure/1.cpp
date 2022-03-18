//
// Created by 倪泽溥 on 2022/3/16.
//

#include "../head.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            auto pos = hash.find(target - num);
            if (pos == hash.end()) {
                hash[num] = i;
            } else {
                ans.push_back(pos->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> res = solution.twoSum(nums, target);
    for_each(res.begin(), res.end(), show);
}