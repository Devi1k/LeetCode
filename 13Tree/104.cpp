//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        return root != nullptr ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};