//
// Created by 倪泽溥 on 2022/4/30.
//
#include "../head.h"

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root)
            return nullptr;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                auto resNode = root->right;
                delete root;
                return resNode;
            } else if (!root->right) {
                auto resNode = root->left;
                delete root;
                return resNode;
            } else if (root->left && root->right) {
                auto cur = root->right;
                while (cur->left)
                    cur = cur->left;
                cur->left = root->left;
                auto temp = root->right;
                delete root;
                return temp;

            }
        }
        return root;
    }
};