//
// Created by 倪泽溥 on 2022/3/5.
//

#include "../head.h"

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;
        for (int i = 0; i < m; ++i) {
            if (flipped)
                break;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }

        int x, y;
        int level = 0;
        while (!points.empty()) {
            ++level;
            int n_points = points.size();
            while (n_points--) {
                auto[r, c] = points.front();
                points.pop();
                for (int i = 0; i < 4; ++i) {
                    x = r + direction[i], y = c + direction[i + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (grid[x][y] == 2)
                            continue;
                        if (grid[x][y] == 1)
                            return level;
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] == 0) {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        for (int k = 0; k < 4; ++k) {
            dfs(points, grid, m, n, i + direction[k], j + direction[k + 1]);
        }
    }
};

int main() {
    vector<vector<int>> A = {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
    };
    Solution solution;
    int ans = solution.shortestBridge(A);
    cout << ans << endl;
    return 0;
}