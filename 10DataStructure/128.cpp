//
// Created by 倪泽溥 on 2022/3/17.
//
#include "../head.h"

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> hash;
        for (const auto &num: nums) {
            hash.insert(num);
        }
        int ans = 0;
        while (!hash.empty()) {
            int cur = *(hash.begin());
            hash.erase(cur);
            int next = cur + 1, prev = cur - 1;
            while (hash.count(next)) {
                hash.erase(next++);
            }
            while (hash.erase(prev)) {
                hash.erase(prev--);
            }
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    cout << solution.longestConsecutive(nums);
}
