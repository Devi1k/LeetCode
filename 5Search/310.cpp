//
// Created by 倪泽溥 on 2022/3/27.
//
#include "../head.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1)
            return {0};
        vector<int> res;
        vector<int> degree(n);
        vector<vector<int>> map(n);
        for (auto &edge: edges) {
            int v1 = edge[0];
            int v2 = edge[1];
            degree[v1]++;
            degree[v2]++;
            map[v1].push_back(v2);
            map[v2].push_back(v1);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1)
                q.push(i);
        }

        while (!q.empty()) {
            res.clear();
            int size = q.size();
            while (size--) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                --degree[cur];
                for (auto i: map[cur]) {
                    --degree[i];
                    if (degree[i] == 1)
                        q.push(i);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> edges = {
            {3, 0},
            {3, 1},
            {3, 2},
            {3, 4},
            {5, 4}
    };
    Solution solution;
    vector<int> res = solution.findMinHeightTrees(6, edges);
    for_each(res.begin(), res.end(), show_num);
}