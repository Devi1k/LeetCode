//
// Created by 倪泽溥 on 2022/5/2.
//
#include "../head.h"

class Solution {
public:
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next, *p = head;
        while (prev != tail) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        while (head) {
            ListNode *tail = head;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            ListNode *next = tail->next;
            tie(head, tail) = reverse(head, tail);
            prev->next = head;
            tail->next = next;
            prev = tail;
            head = tail->next;
        }
        return dummy->next;
    }
};