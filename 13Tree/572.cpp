//
// Created by 倪泽溥 on 2022/4/27.
//
#include "../head.h"

class Solution {
public:
    vector<int> sOrder, tOrder;
    int maxElement, lNull, rNull;

    void getMaxElement(TreeNode *o) {
        if (!o)
            return;
        maxElement = max(maxElement, o->val);
        getMaxElement(o->left);
        getMaxElement(o->right);

    }

    void getDfsOrder(TreeNode *o, vector<int> &tar) {
        if (!o)
            return;
        tar.emplace_back(o->val);
        if (o->left)
            getDfsOrder(o->left, tar);
        else
            tar.emplace_back(lNull);
        if (o->right)
            getDfsOrder(o->right, tar);
        else
            tar.emplace_back(rNull);
    }

    bool kmp() {
        int sLen = sOrder.size(), tLen = tOrder.size();
        vector<int> fail(tOrder.size());
        //next数组
        for (int i = 1, j = 0; i < tLen; ++i) {
            while (j > 0 && tOrder[i] != tOrder[j])
                j = fail[j - 1];
            if (tOrder[i] == tOrder[j])
                ++j;
            fail[i] = j;
        }
        //匹配
        for (int i = 0, j = 0; i < sLen; ++i) {
            while (j > 0 && sOrder[i] != tOrder[j])
                j = fail[j - 1];
            if (sOrder[i] == tOrder[j])
                ++j;
            if (j == tLen)
                return true;
        }
        return false;
    }


    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        maxElement = INT_MIN;
        getMaxElement(root);
        getMaxElement(subRoot);
        lNull = maxElement + 1;
        rNull = maxElement + 2;
        getDfsOrder(root, sOrder);
        getDfsOrder(subRoot, tOrder);
        return kmp();

    }
};

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
    Solution solution;
    vector<int> rootInorder = {8, 12, 3, 10, 11, 6};
    vector<int> rootPostorder = {8, 3, 12, 11, 6, 10};
    vector<int> subRootInorder = {8, 12, 10, 6};
    vector<int> subRootPostorder = {8, 12, 6, 10};
    TreeNode *root = buildTree(rootInorder, rootPostorder);
    TreeNode *subRoot = buildTree(subRootInorder, subRootPostorder);

    cout << solution.isSubtree(root, subRoot);
}