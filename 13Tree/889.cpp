//
// Created by 倪泽溥 on 2022/4/29.
//
#include "../head.h"

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        if (empty(preorder))
            return nullptr;
        unordered_map<int, int> hash;
        for (int i = 0; i < preorder.size(); ++i) {
            hash[postorder[i]] = i;
        }
        return buildTreeHelper(hash, preorder, 0, preorder.size() - 1, 0);
    }

    /**
     *
     * @param hash 后序哈希
     * @param preorder 前序数组
     * @param post_start 后序开始位置
     * @param post_end 后序结束位置
     * @param pre_start 根在前序里的索引
     * @return
     */
    TreeNode *
    buildTreeHelper(unordered_map<int, int> &hash, vector<int> &preorder, int post_start, int post_end, int pre_start) {
        if (post_start > post_end)
            return nullptr;
        int root = preorder[pre_start];
        TreeNode *node = new TreeNode(root);
        if (post_start == post_end)
            return node;
        // left_start：左子树根在后序中的索引,以left_start为分割
        int left_start = hash[preorder[pre_start + 1]], leftLen = left_start - post_start + 1;
        node->left = buildTreeHelper(hash, preorder, post_start, left_start, pre_start + 1);
        node->right = buildTreeHelper(hash, preorder, left_start + 1, post_end - 1, pre_start + leftLen + 1);
        return node;
    }
};

int main() {
    Solution solution;
    vector<int> preorder = {1, 2, 4, 3, 6, 7};
    vector<int> postorder = {4, 2, 6, 7, 3, 1};
    TreeNode *root = solution.constructFromPrePost(preorder, postorder);
}