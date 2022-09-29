//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int depth = max(left, right) + 1;
        return depth;
//        return root == nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};