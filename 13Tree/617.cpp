//
// Created by 倪泽溥 on 2022/4/27.
//
#include "../head.h"

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root2)
            return root1;
        if (!root1)
            return root2;
        TreeNode *merge = new TreeNode(root1->val + root2->val);
        merge->left = mergeTrees(root1->left, root2->left);
        merge->right = mergeTrees(root1->right, root2->right);
        return merge;
    }
};