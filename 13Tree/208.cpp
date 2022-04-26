//
// Created by 倪泽溥 on 2022/4/26.
//
#include "../head.h"

class TrieNode {
public:
    TrieNode *childNode[26];
    bool isVal;

    TrieNode() : isVal(false) {
        for (int i = 0; i < 26; ++i) {
            childNode[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() : root(new TrieNode()) {

    }

    void insert(string word) {
        TrieNode *temp = root;
        for (char i: word) {
            if (!temp->childNode[i - 'a'])
                temp->childNode[i - 'a'] = new TrieNode;
            temp = temp->childNode[i - 'a'];
        }
        temp->isVal = true;
    }

    bool search(string word) {
        TrieNode *temp = root;
        for (char i: word) {
            if (!temp)
                break;
            temp = temp->childNode[i - 'a'];
        }
        return temp != nullptr && temp->isVal;
    }

    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for (char i: prefix) {
            if (!temp)
                break;
            temp = temp->childNode[i - 'a'];
        }
        return temp;
    }
};


int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->search("apple");
    trie->search("app");
    trie->startsWith("app");
    trie->insert("app");
    trie->search("app");

}