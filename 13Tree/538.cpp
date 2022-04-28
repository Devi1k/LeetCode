//
// Created by 倪泽溥 on 2022/4/28.
//
#include "../head.h"

class Solution {

public:
    int sum = 0;

    TreeNode *convertBST(TreeNode *root) {
        if (!root) {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};