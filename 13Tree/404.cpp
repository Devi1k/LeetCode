//
// Created by 倪泽溥 on 2022/4/28.
//
#include "../head.h"

class Solution {
public:
    bool isLeaf(TreeNode *node) {
        if (!node->right && !node->left)
            return true;
        return false;
    }

    int dfs(TreeNode *root) {
        int ans = 0;
        if (root->left)
            ans += isLeaf(root->left) ? root->left->val : dfs(root->left);
        if (root->right && !isLeaf(root->right))
            ans += dfs(root->right);
        return ans;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        return root ? dfs(root) : 0;
    }
};