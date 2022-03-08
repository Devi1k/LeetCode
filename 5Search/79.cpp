//
// Created by 倪泽溥 on 2022/3/4.
//
#include "../head.h"

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }

    void
    backtracking(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited,
                 int pos) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if (visited[i][j] || find || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1) {
            find = true;
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < 3; ++k) {
            int x = i + direction[k], y = j + direction[k + 1];
            backtracking(x, y, board, word, find, visited, pos + 1);
        }
        visited[i][j] = false;
    }


};