//
// Created by 倪泽溥 on 2022/9/28.
//
#include "iostream"
#include "queue"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> per;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                per.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(per);
        }
        return res;
    }
};