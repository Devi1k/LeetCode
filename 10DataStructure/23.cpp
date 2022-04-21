//
// Created by 倪泽溥 on 2022/3/14.
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

struct Comp {
    bool operator()(ListNode *l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, Comp> q;
        for (ListNode *list: lists) {
            if (list)
                q.push(list);
        }
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if (cur->next)
                q.push(cur->next);
        }
        return dummy->next;
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
    vector<ListNode *> list;
    list.emplace_back(construst({1, 4, 5}));
    list.emplace_back(construst({1, 3, 4}));
    list.emplace_back(construst({2, 6}));
    Solution solution;
    ListNode *res = solution.mergeKLists(list);
    show(res);
}