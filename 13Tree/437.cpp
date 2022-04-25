//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        return root ? pathSumStartWithRoot(root, targetSum) + pathSum(root->left, targetSum) +
                      pathSum(root->right, targetSum) : 0;
    }

    int pathSumStartWithRoot(TreeNode *root, int sum) {
        if (!root)
            return 0;
        int count = root->val == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, sum - root->val);
        count += pathSumStartWithRoot(root->right, sum - root->val);
        return count;
    }
};
