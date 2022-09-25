//
// Created by 倪泽溥 on 2022/3/12.
//
#include "stack"

using namespace std;

class MyQueue {
private:
    stack<int> in, out;
public:
    MyQueue() {

    }

    int pop() {
        int p;
        if (!out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        p = out.top();
        out.pop();
        return p;
    }

    void push(int x) {
        in.push(x);
    }


    int peek() {
        int p;
        if (!out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        p = out.top();
        return p;
    }


    bool empty() {
        return in.empty() && out.empty();
    }
};