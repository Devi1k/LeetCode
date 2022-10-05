//
// Created by 倪泽溥 on 2022/10/5.
//
#include "../head.h"

class Solution {
private:
    void traversal(TreeNode *cur, string path, vector<string> &result) {
        path += to_string(cur->val);
        if (!cur->left && !cur->right) {
            result.push_back(path);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path + "->", result);
        }
        if (cur->right) {
            traversal(cur->right, path + "->", result);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        string path;
        if (!root) return result;
        traversal(root, path, result);
        return result;
    }


};