//
// Created by 倪泽溥 on 2022/4/27.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }


};