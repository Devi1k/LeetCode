//
// Created by 倪泽溥 on 2022/3/1.
//
#include "../head.h"

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j) {
        if (cur_i < 0 || cur_j < 0 || cur_i >= grid.size() || cur_j >= grid[1].size()) {
            return 0;
        }
        if (grid[cur_i][cur_j] == 0)
            return 0;
        else {
            grid[cur_i][cur_j] = 0;
            int ans = 1;
            int di[4] = {0, 0, -1, 1};
            int dj[4] = {1, -1, 0, 0};
            for (int i = 0; i < 4; ++i) {
                int next_i = cur_i + di[i];
                int next_j = cur_j + dj[i];
                ans += dfs(grid, next_i, next_j);
            }
            return ans;
        }
    }

//    int maxAreaOfIsland(vector<vector<int>> &grid) {
//        int ans = 0;
//        for (int i = 0; i < grid.size(); ++i) {
//            for (int j = 0; j < grid[0].size(); ++j) {
//                ans = max(ans, dfs(grid, i, j));
//            }
//        }
//        return ans;
//    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int cur = 0;
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);
                while (!stacki.empty()) {
                    int cur_i = stacki.top(), cur_j = stackj.top();
                    stacki.pop();
                    stackj.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i >= grid.size() || cur_j >= grid[0].size())
                        continue;
                    if (grid[cur_i][cur_j] == 0)
                        continue;
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    vector<int> di = {0, 0, -1, 1};
                    vector<int> dj = {1, -1, 0, 0};
                    for (int k = 0; k < 4; ++k) {
                        int next_i = cur_i + di[k], next_j = cur_j + dj[k];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
            {1, 0, 1, 1, 0, 1, 0, 1},
            {1, 0, 1, 1, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 1}
    };
    Solution solution;
    cout << solution.maxAreaOfIsland(grid) << endl;
    return 0;
}