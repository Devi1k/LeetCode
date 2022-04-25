//
// Created by 倪泽溥 on 2022/4/25.
//
#include "../head.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            double sum = 0;
            for (int i = 0; i < count; ++i) {
                TreeNode *node = q.front();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.emplace_back(sum / count);
        }
        return ans;

    }
};