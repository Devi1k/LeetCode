//
// Created by 倪泽溥 on 2022/3/9.
//
#include "../head.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int temp, n = matrix.size() - 1;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j] = matrix[j][n - i];
                matrix[j][n - i] = temp;
            }
        }
    }
};

void show(int x) {
    cout << x << " ";
}

int main() {
    vector<vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16},
    };
    Solution solution;
    solution.rotate(matrix);
    for (const auto &m: matrix) {
        for_each(m.begin(), m.end(), show);
        cout << endl;
    }
}
