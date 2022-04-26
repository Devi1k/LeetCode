//
// Created by 倪泽溥 on 2022/4/26.
//
#include "../head.h"

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root)
            return nullptr;
        if (root->val > high) {
            return trimBST(root->left, low, high);
        } else if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

TreeNode *buildTreeHelper(unordered_map<int, int> &hash, vector<int> &postorder, int s0, int e0, int e1) {
    if (s0 > e0)
        return nullptr;
    int mid = postorder[e1], index = hash[mid], rightLen = e0 - index;
    TreeNode *node = new TreeNode(mid);
    node->right = buildTreeHelper(hash, postorder, index + 1, e0, e1 - 1);
    node->left = buildTreeHelper(hash, postorder, s0, index - 1, e1 - rightLen - 1);
    return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty())
        return nullptr;
    unordered_map<int, int> hash;
    for (int i = 0; i < inorder.size(); ++i) {
        hash[inorder[i]] = i;
    }
    return buildTreeHelper(hash, postorder, 0, postorder.size() - 1, postorder.size() - 1);
}

int main() {
    vector<int> inorder = {0, 1, 2, 3, 4};
    vector<int> postorder = {1, 2, 0, 4, 3};
    TreeNode *root = buildTree(inorder, postorder);
    Solution solution;
    solution.trimBST(root, 1, 3);
}