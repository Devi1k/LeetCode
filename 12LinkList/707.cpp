//
// Created by 倪泽溥 on 2022/7/18.
//
#include "iostream"

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int val) : val(val), next(nullptr) {}
    };

    ListNode *dummyHead = new ListNode(0);
    int _size = 0;

    MyLinkedList() {

    }

    int get(int index) {
        if (index >= _size || index < 0) return -1;
        ListNode *node = dummyHead->next;
        while (index--) {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        _size += 1;
    }

    void addAtTail(int val) {
        ListNode *node = dummyHead;
        while (node->next) {
            node = node->next;
        }
        ListNode *newNode = new ListNode(val);
        node->next = newNode;
        _size += 1;
    }

    void addAtIndex(int index, int val) {
        if (index >= _size + 1 || index < 0) return;
        auto *newNode = new ListNode(val);
        ListNode *node = dummyHead;
        while (index--) {
            node = node->next;
        }
        newNode->next = node->next;
        node->next = newNode;
        ++_size;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        ListNode *node = dummyHead;
        while (index--) {
            node = node->next;
        }
        ListNode *tmp = node->next;
        node->next = node->next->next;
        delete tmp;
        --_size;

    }
};

int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);

    int param_1 = obj->get(1);
    cout << param_1;
    obj->deleteAtIndex(1);
    int param_2 = obj->get(1);

    cout << param_2;
}
