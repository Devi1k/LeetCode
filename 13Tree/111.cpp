//
// Created by 倪泽溥 on 2022/10/4.
//
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && root->right) {
            return 1 + minDepth(root->right);
        }
        if (!root->right && root->left) {
            return 1 + minDepth(root->left);
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};