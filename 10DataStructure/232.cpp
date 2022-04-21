//
// Created by 倪泽溥 on 2022/3/12.
//
#include "../head.h"

class MyQueue {
    stack<int> in, out;
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                int transfer = in.top();
                out.push(transfer);
                in.pop();
            }
        }
        int x = out.top();
        out.pop();
        return x;
    }

    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                int transfer = in.top();
                out.push(transfer);
                in.pop();
            }
        }
        int x = out.top();
        return x;
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};