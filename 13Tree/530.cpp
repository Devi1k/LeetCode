//
// Created by 倪泽溥 on 2022/4/28.
//
#include "../head.h"

class Solution {
public:
    int ans = INT_MAX, pre = -1;

    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        if (pre == -1)
            pre = root->val;
        else {
            ans = min(abs(pre - root->val), ans);
            pre = root->val;
        }
        dfs(root->right);
    }
};