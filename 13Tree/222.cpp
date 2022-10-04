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
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int left_nums = 0, right_nums = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        while (left) {
            left = left->left;
            ++left_nums;
        }
        while (right) {
            right = right->right;
            ++right_nums;
        }
        if (left_nums == right_nums) return (2 << left_nums) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};