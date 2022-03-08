//
// Created by 倪泽溥 on 2022/3/2.
//
#include "../head.h"

class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int provinces, int i) {
        for (int j = 0; j < provinces; ++j) {
            cout << i;
            cout << j << endl;

            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, provinces, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected) {
        int provinces = isConnected.size();
        vector<bool> visited(provinces);
        int circle = 0;
        for (int i = 0; i < provinces; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, provinces, i);
                ++circle;
            }
        }
        return circle;
    }
};

int main() {
    vector<vector<int>> M = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
    };
    Solution solution;
    cout << solution.findCircleNum(M) << endl;

    return 0;
}

