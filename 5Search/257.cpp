//
// Created by 倪泽溥 on 2022/3/12.
//
#include "../head.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void construct(TreeNode *root, string path, vector<string> &paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr)
                paths.push_back(path);
            else {
                path += "->";
                construct(root->left, path, paths);
                construct(root->right, path, paths);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> paths;
        construct(root, "", paths);
        return paths;
    }
};
