//
// Created by 倪泽溥 on 2022/3/1.
//

#ifndef LEETCODE_HEAD_H
#define LEETCODE_HEAD_H

#endif //LEETCODE_HEAD_H

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numeric>

using namespace std;

void show_num(int x) {
    cout << x << " ";
}

void show_string(string x) {
    cout << x << " ";
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
