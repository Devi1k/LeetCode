//
// Created by 倪泽溥 on 2022/4/23.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *prev = head, *cur = head->next;
        while (cur) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
