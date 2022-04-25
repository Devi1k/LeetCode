//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }


    int helper(TreeNode *root, int &diameter) {
        if (!root)
            return 0;
        int l = helper(root->left, diameter), r = helper(root->right, diameter);
        diameter = max(l + r, diameter);
        return max(l, r) + 1;
    }
};

int main() {
    vector<int> array = {};
    TreeNode *root = construct(array);
    Solution solution;
    cout << solution.diameterOfBinaryTree(root);
}