//
// Created by 倪泽溥 on 2022/4/24.
//

#include "../head.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head)
            return nullptr;
        int length = 0;
        ListNode *node = head;
        while (node) {
            ++length;
            node = node->next;
        }
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; ++subLength) {
            ListNode *prev = dummyHead, *curr = dummyHead->next;
            while (curr) {
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr->next; ++i) {
                    curr = curr->next;
                }
                ListNode *head2 = curr;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr && curr->next; ++i) {
                    curr = curr->next;
                }
                ListNode *next = nullptr;
                if (curr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;

    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 && temp2) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        temp->next = temp1 == nullptr ? temp2 : temp1;
        return dummyHead->next;
    }
};


ListNode *construst(const vector<int> &array) {
    auto *head = new ListNode(array[0]);
    ListNode *p, *s;
    p = head;
    for (int i = 1; i < array.size(); i++) {
        s = new ListNode(array[i]);
        p->next = s;
        p = p->next;
    }
    return head;
}

void show(ListNode *listNode) {
    ListNode *p;
    p = listNode;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

}

int main() {
    Solution solution;
    vector<int> array1 = {4, 2, 1, 3};

    ListNode *list = construst(array1);
    ListNode *res = solution.sortList(list);
    show(res);

}