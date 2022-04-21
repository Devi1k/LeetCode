//
// Created by 倪泽溥 on 2022/3/14.
//
#include "../head.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap;
        int i = 0, len = buildings.size();
        int cur_x, cur_h;
        while (i < len || !max_heap.empty()) {
            // 有重叠的两栋楼
            if (max_heap.empty() || i < len && buildings[i][0] <= max_heap.top().second) {
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0]) {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    i++;
                }
            } else {
                // 没有重叠
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> buildings = {{2,  9,  10},
                                     {3,  7,  15},
                                     {5,  12, 12},
                                     {15, 20, 10},
                                     {19, 24, 8}};
    Solution solution;
    vector<vector<int>> res = solution.getSkyline(buildings);
    for (auto &r: res) {
        for_each(r.begin(), r.end(), show);
        cout << endl;
    }
}