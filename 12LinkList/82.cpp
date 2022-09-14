//
// Created by zepu.ni on 2022/9/14.
//
# include "../head.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next->val == x && cur->next) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;


        ListNode *tmp = head;
        set<int> s, t;
        while (tmp) {
            if (s.find(tmp->val) != s.end()) {
                t.insert(tmp->val);
            }
            s.insert(tmp->val);
            tmp = tmp->next;
        }
        ListNode *prev = new ListNode();
        ListNode *dummyHead = new ListNode();
        prev->next = head;
        dummyHead = prev;
        tmp = head;
        while (tmp) {
            if (t.find(tmp->val) != t.end()) {
                ListNode *del = tmp;
                prev->next = tmp->next;
                tmp = tmp->next;
                delete del;
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        head = dummyHead->next;
        return head;
    }

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
};


int main() {
    vector<int> nums = {1, 1, 1, 2, 3};
    Solution solution;
    ListNode *head = solution.construst(nums);
    ListNode *res = solution.deleteDuplicates(head);
    while (res) {
        cout << res->val;
        res = res->next;
    }
}
