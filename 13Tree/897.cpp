//
// Created by 倪泽溥 on 2022/4/30.
//
#include "../head.h"

class Solution {
private:
    TreeNode *resNode;
public:
    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        resNode->right = root;
        root->left = nullptr;
        resNode = root;
        inorder(root->right);
    }


    TreeNode *increasingBST(TreeNode *root) {
        auto *dummyHead = new TreeNode(-1);
        resNode = dummyHead;
        inorder(root);
        return dummyHead->right;

    }
};