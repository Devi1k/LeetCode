//
// Created by 倪泽溥 on 2022/4/24.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else {
            if (!left && right || left && !right) {
                return false;
            }
            if (left->val == right->val) {
                return symmetric(left->left, right->right) && symmetric(left->right, right->left);
            } else {
                return false;
            }
        }

    }

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return symmetric(root->left, root->right);

    }
};
