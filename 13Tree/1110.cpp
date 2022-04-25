//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode *> forest;
        unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = helper(root, dict, forest);
        if (root)
            forest.emplace_back(root);
        return forest;
    }


    TreeNode *helper(TreeNode *root, unordered_set<int> &dict, vector<TreeNode *> &forest) {
        if (!root)
            return root;
        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        if (dict.count(root->val)) {
            if (root->left)
                forest.emplace_back(root->left);
            if (root->right)
                forest.emplace_back(root->right);
            root = nullptr;
        }
        return root;
    }
};