//
// Created by 倪泽溥 on 2022/4/29.
//
#include "../head.h"

class Solution {
public:
//    vector<int> postorderTraversal(TreeNode *root) {
//        vector<int> res;
//        if (!root)
//            return res;
//        helper(root,res);
//        return res;
//    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            res.emplace_back(node->val);
            if (node->left)
                st.push(root->left);
            if (node->right)
                st.push(root->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            res.emplace_back(node->val);
            if (node->left)
                st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right)
                st.push(node->right); // 空节点不入栈
        }
        reverse(res.begin(), res.end()); // 将结果反转之后就是左右中的顺序了
        return res;
    }


    void helper(TreeNode *root, vector<int> &res) {
        if (root->left)
            helper(root->left, res);
        if (root->right)
            helper(root->right, res);
        res.emplace_back(root->val);
    }
};