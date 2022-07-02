
//
// Created by 倪泽溥 on 2022/4/22.
//
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *next, *prev;
        prev = nullptr;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return next;

    }

    ListNode *reverseList(ListNode *head, ListNode *prev = nullptr) {
        if (!head)
            return prev;
        ListNode *next = head->next;
        head->next = prev;
        reverseList(next, head);
    }
};