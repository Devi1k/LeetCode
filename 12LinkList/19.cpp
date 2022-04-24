//
// Created by 倪泽溥 on 2022/4/24.
//
#include "../head.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        ListNode *del = second->next;
        second->next = del->next;
        delete del;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};