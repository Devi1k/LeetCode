//
// Created by 倪泽溥 on 2022/4/28.
//
#include "../head.h"

class Solution {
public:
    int res, maxDepth = INT_MIN;

    int findBottomLeftValue(TreeNode *root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int depth) {
        if (!root)
            return;
        // 由于是深度优先，如果同层有超过一个节点的时候只会记第一个值，也就是最左边的
        if (maxDepth < depth) {
            maxDepth = depth;
            res = root->val;
        }
        ++depth;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
};
