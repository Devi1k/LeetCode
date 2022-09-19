//
// Created by 倪泽溥 on 2022/4/25.
//
#include "vector"
#include "unordered_map"
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}


};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < preorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return helper(preorder, hash, 0, preorder.size() - 1, 0);
    }

    TreeNode *helper(vector<int> &preorder, unordered_map<int, int> &hash, int s0, int e0, int s1) {
        if (s0 > e0) return nullptr;
        int mid = preorder[s1], index = hash[mid], left_length = index - s0;
        TreeNode *root = new TreeNode(mid);
        root->left = helper(preorder, hash, s0, index - 1, s1 + 1);
        root->right = helper(preorder, hash, index + 1, e0, s1 + left_length + 1);
        return root;
    }
};


int main() {
    Solution solution;
    vector<int> preorder = {4, 9, 20, 15, 7};
    vector<int> inorder = {9, 4, 15, 20, 7};
    TreeNode *root = solution.buildTree(preorder, inorder);
    cout << root->val;
}