//
// Created by 倪泽溥 on 2022/5/31.
//
#include "../head.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return help(preorder, hash, 0, preorder.size() - 1, 0);
    }

    TreeNode *help(vector<int> &preorder, unordered_map<int, int> &hash, int start, int end, int s0) {
        if (start > end) return nullptr;
        int r = preorder[s0], index = hash[r], left_length = index - start;
        TreeNode *root = new TreeNode(r);
        root->left = help(preorder, hash, start, index - 1, s0 + 1);
        root->right = help(preorder, hash, index + 1, end, s0 + left_length + 1);
        return root;
    }
};

int main() {
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = solution.buildTree(preorder, inorder);
    cout << root->val;
}