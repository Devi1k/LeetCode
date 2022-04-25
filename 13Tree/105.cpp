//
// Created by 倪泽溥 on 2022/4/25.
//
#include "../head.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < preorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return buildTreeHelper(hash, preorder, 0, preorder.size() - 1, 0);
    }

    /**
     *
     * @param hash 中序hash表
     * @param preorder 前序数组
     * @param s0 中序起始索引
     * @param e0 中序终止索引
     * @param s1 根所在前序的索引
     * @return 树的根节点
     */
    TreeNode *buildTreeHelper(unordered_map<int, int> &hash, vector<int> &preorder, int s0, int e0, int s1) {
        if (s0 > e0)
            return nullptr;
        // mid：根的值， index：中序里根的索引，leftLen：中序里左子树（子数组）的长度
        int mid = preorder[s1], index = hash[mid], leftLen = index - s0 - 1;
        TreeNode *node = new TreeNode(mid);
        node->left = buildTreeHelper(hash, preorder, s0, index - 1, s1 + 1);
        node->right = buildTreeHelper(hash, preorder, index + 1, e0, s1 + 2 + leftLen);
        return node;
    }
};


int main() {
    Solution solution;
    vector<int> preorder = {4, 9, 20, 15, 7};
    vector<int> inorder = {9, 4, 15, 20, 7};
    TreeNode *root = solution.buildTree(preorder, inorder);
}