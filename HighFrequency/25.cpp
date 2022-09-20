//
// Created by 倪泽溥 on 2022/5/2.
//
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int val) : val(val), next(nullptr) {}

    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    pair<ListNode *, ListNode *> reverse_partial(ListNode *head, ListNode *tail) {
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
        ListNode *dummy_head = new ListNode(0, head);
        ListNode *prev = dummy_head;
        while (head) {
            ListNode *tail = prev;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return dummy_head->next;
                }
            }
            ListNode *next = tail->next;
            tie(head, tail) = reverse_partial(head, tail);
            prev->next = head;
            tail->next = next;
            prev = tail;
            head = tail->next;
        }
        return dummy_head->next;
    }
};