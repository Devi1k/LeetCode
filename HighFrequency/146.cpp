//
// Created by 倪泽溥 on 2022/5/2.
//


#include "unordered_map"

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;

    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkedNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size, capacity;
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode *node = cache[key];
        move_to_head(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // insert
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            add_to_head(node);
            ++size;
            if (size > capacity) {
                DLinkedNode *remove = remove_tail();
                cache.erase(remove->key);
                delete remove;
                --size;
            }
        } else {
            // update
            DLinkedNode *node = cache[key];
            node->value = value;
            move_to_head(node);
        }
    }


    void move_to_head(DLinkedNode *node) {
        remove_node(node);
        add_to_head(node);
    }


    DLinkedNode *remove_tail() {
        DLinkedNode *node = tail->prev;
        remove_node(node);
        return node;
    }


    void remove_node(DLinkedNode *node) {
        DLinkedNode *prev = node->prev;
        DLinkedNode *next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void add_to_head(DLinkedNode *node) {
        DLinkedNode *next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }
};

