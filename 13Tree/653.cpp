//
// Created by 倪泽溥 on 2022/4/30.
//
#include "../head.h"

class Solution {
public:
    unordered_set<int> hash;

    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;
        if (hash.count(k - root->val))
            return true;
        hash.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right);
    }
};