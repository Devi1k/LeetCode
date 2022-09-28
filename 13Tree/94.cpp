//
// Created by 倪泽溥 on 2022/4/29.
//
#include "stack"
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
//    vector<int> inorderTraversal(TreeNode *root) {
//        vector<int> res;
//        if (!root)
//            return res;
//        helper(root,res);
//        return res;
//    }


    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> res;
        if (!root) return res;
        TreeNode *cur = root;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }


    void helper(TreeNode *root, vector<int> &res) {
        if (root->left)
            helper(root->left, res);
        res.emplace_back(root->val);
        if (root->right)
            helper(root->right, res);
    }
};