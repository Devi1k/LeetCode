//
// Created by 倪泽溥 on 2022/3/12.
//
#include "../head.h"

class Solution {
public:
    vector<int> direction = {-1, 0, 1, 0, -1};

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        for (int i = 0; i < direction.size(); ++i) {
            int x_ = x + direction[i], y_ = y + direction[i + 1];
            dfs(board, x_, y_);
        }
    }

    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; ++i) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
    };
    solution.solve(board);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}