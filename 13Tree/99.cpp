//
// Created by 倪泽溥 on 2022/4/26.
//
#include "../head.h"

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;
        inorder(root, mistake1, mistake2, prev);
        if (mistake1 && mistake2) {
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }

    void inorder(TreeNode *root, TreeNode *&mistake1, TreeNode *&mistake2, TreeNode *&prev) {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, mistake1, mistake2, prev);
        if (prev && root->val < prev->val) {
            if (!mistake1) {
                mistake1 = prev;
                mistake2 = root;
            } else
                mistake2 = root;
        }
        prev = root;
        if (root->right) {
            inorder(root->right, mistake1, mistake2, prev);
        }
    }

};

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
    vector<int> inorder = {1, 3, 2, 4};
    vector<int> postorder = {1, 2, 4, 3};
    TreeNode *root = buildTree(inorder, postorder);
    Solution solution;
    solution.recoverTree(root);
}

