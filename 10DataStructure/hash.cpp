//
// Created by 倪泽溥 on 2022/3/16.
//
#include "../head.h"

class HashTable {
private:
    vector<list<T>> hash_table;

    int myhash(const T &obj) const {
        return hash(obj, hash_table.size());
    }

public:
    HashTable(int size = 31) {
        hash_table.reserve(size);
        hash_table.resize(size);
    }

    ~HashTable() {}

    bool contains(const T &obj) {
        int hash_value = myhash(obj);
        const list<T> &slot = hash_table[hash_value];
        list<T>::const_iterator it = slot.cbegin();
        for (; it < slot.cend() && it != obj; ++it);
        return it != slot.cend();
    }


    bool insert(const T &obj) {
        if (contains(obj)) {
            return false;
        }
        int hash_value = myhash(obj);
        list<T> &slot = hash_table[hash_value];
        slot.push_front(obj);
    }

    bool remove(const T &obj) {
        list<T> &slot = hash_table[myhash(obj)];
        auto it = find(slot.begin(), slot.end(), obj);
        if (it == slot.end()) {
            return false;
        }
        slot.erase(it);
        return true;
    }
};


int hash(const int &key, const int &tableSize) {
    return key % tableSize;
}