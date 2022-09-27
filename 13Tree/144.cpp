//
// Created by 倪泽溥 on 2022/4/25.
//
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> res;
//        if (!root) return res;
//        traversal(root, res);
//        return res;
//    }

    void traversal(TreeNode *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        if (root->left)
            traversal(root->left, res);
        if (root->right)
            traversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> tree;
        vector<int> res;
        if (!root) return res;
        tree.push(root);
        while (!tree.empty()) {
            TreeNode *node = tree.top();
            tree.pop();
            res.push_back(node->val);
            if (node->right)
                tree.push(node->right);
            if (node->left)
                tree.push(node->left);
        }
        return res;
    }


};