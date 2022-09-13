//
// Created by 倪泽溥 on 2022/7/4.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1, loop = n / 2, mid = n / 2, offset = 1;
        int start_x = 0, start_y = 0;
        int i, j;
        while (loop--) {
            i = start_x, j = start_y;
            for (j = start_y; j < start_y + n - offset; ++j) {
                res[start_x][j] = count++;
            }
            for (i = start_x; i < start_x + n - offset; ++i) {
                res[i][start_y] = count++;
            }
            for (; j > start_y; --j) {
                res[i][j] = count++;
            }
            for (; i > start_x; --i) {
                res[i][j] = count++;
            }
            ++start_x, ++start_y;
            offset += 2;
        }
        if (n % 2) res[mid][mid] = count;
        return res;
    }
};