//
// Created by 倪泽溥 on 2022/4/25.
//
#include "../head.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty())
            return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return buildTreeHelper(hash, postorder, 0, postorder.size() - 1, postorder.size() - 1);
    }

    /**
     *
     * @param hash 中序hash表
     * @param preorder 后序数组
     * @param s0 中序起始索引
     * @param e0 中序终止索引
     * @param s1 根所在后序的索引
     * @return 树的根节点
     */
    TreeNode *buildTreeHelper(unordered_map<int, int> &hash, vector<int> &postorder, int s0, int e0, int e1) {
        if (s0 > e0)
            return nullptr;
        int mid = postorder[e1], index = hash[mid], rightLen = e0 - index;
        TreeNode *node = new TreeNode(mid);
        node->right = buildTreeHelper(hash, postorder, index + 1, e0, e1 - 1);
        node->left = buildTreeHelper(hash, postorder, s0, index - 1, e1 - rightLen - 1);
        return node;
    }
};

int main() {
    Solution solution;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = solution.buildTree(inorder, postorder);
}