//
// Created by 倪泽溥 on 2022/3/1.
//
#include "../head.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int &num: nums) {
            max_count = max(max_count, ++counts[num]);
        }
        // budget本身的下标就是频率，所以budget的空间是cnt
        //     方便统计，保证下标统一，所以是cnt+1
        vector<vector<int>> buckets(max_count + 1);
        for (const auto &p: counts) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i) {
            for (const int &num: buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 4};
    int k = 2;
    vector<int> ans = solution.topKFrequent(nums, k);
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
    return 0;
}