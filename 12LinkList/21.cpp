//
// Created by 倪泽溥 on 2022/4/22.
//

#include "../head.h"

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *head = new ListNode(0);
        ListNode *prev = head;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return head->next;

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
    vector<int> array1 = {1, 2};
    vector<int> array2 = {4, 5};
    ListNode *list1 = construst(array1);
    ListNode *list2 = construst(array2);
    ListNode *res = solution.mergeTwoLists(list1, list2);
    show(res);

}