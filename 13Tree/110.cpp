//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }

    int depth(TreeNode *root) {
        if (!root)
            return -1;
        int left = depth(root->left), right = depth(root->right);
        if (left == -1 || right == -1 || abs(right - left) > 1)
            return -1;
        return 1 + max(left, right);
    }
};