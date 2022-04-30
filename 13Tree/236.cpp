//
// Created by 倪泽溥 on 2022/4/30.
//
#include "../head.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        if (left && right)
            return root;
        return nullptr;
    }
};