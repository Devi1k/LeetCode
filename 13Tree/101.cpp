//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return root == nullptr || isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if ((!left && right) || (left && !right))
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
