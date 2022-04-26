//
// Created by 倪泽溥 on 2022/4/26.
//

#ifndef LEETCODE_BST_H
#define LEETCODE_BST_H

template<class T>
class BST {
    struct Node {
        T data;
        Node *left;
        Node *right;
    };

    Node *root;

    Node *makeEmpty(Node *t) {
        if (!t)
            return nullptr;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return nullptr;
    }

    Node *insert(Node *t, T x) {
        if (!t) {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
        } else if (x < t->data) {
            t->left = insert(t->left, x);
        } else if (x > t->data) {
            t->right = insert(t->right, x);
        }
        return t;
    }

    Node *findMin(Node *t) {
        if (!t || !(t->left))
            return t;
        return findMin(t->left);
    }

    Node *findMax(Node *t) {
        if (!t || !(t->right))
            return t;
        return findMax(t->right);
    }

    Node *remove(Node *t, T x) {
        Node *temp;
        if (!t)
            return nullptr;
        else if (x < t->data)
            t->left = remove(t->left, x);
        else if (x > t->data)
            t->right = remove(t->right, x);
        else if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->right, t->data);
        } else {
            temp = t;
            if (t->right == nullptr)
                t = t->left;
            else if (t->left == nullptr)
                t = t->right;
            delete temp;
        }
        return t;
    }
};


#endif //LEETCODE_BST_H
