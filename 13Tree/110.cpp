//
// Created by 倪泽溥 on 2022/4/24.
//
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return getDepth(root) != -1;
    }

    int getDepth(TreeNode *root) {
        if (!root) return 0;
        int left = getDepth(root->left), right = getDepth(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        } else {
            return 1 + max(left, right);
        }
    }
};