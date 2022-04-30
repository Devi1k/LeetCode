//
// Created by 倪泽溥 on 2022/4/30.
//
#include "../head.h"''

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return buildTree(head, nullptr);
    }

    TreeNode *buildTree(ListNode *begin, ListNode *end) {
        if (begin == end)
            return nullptr;
        ListNode *slow = begin, *fast = begin;
//        while (fast!=end && fast->next!=end) {
        while (fast->next != end && fast->next->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        auto *root = new TreeNode(mid->val);
        root->left = buildTree(begin, mid);
        root->right = buildTree(mid->next, end);
        return root;
    }
};