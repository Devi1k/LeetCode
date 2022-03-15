//
// Created by 倪泽溥 on 2022/3/14.
//
#include "../head.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> indices;
        for (int i = 0; i < n; ++i) {
            while (!indices.empty()) {
                int pre_index = indices.top();
                if (temperatures[i] <= temperatures[pre_index]) {
                    break;
                }
                indices.pop();
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};


int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution solution;
    vector<int> res = solution.dailyTemperatures(temp);
    for_each(res.begin(), res.end(), show);
}
