//
// Created by 倪泽溥 on 2022/3/20.
//
#include "../head.h"

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        int size = q1.size(), res;
        while (--size) {
            q2.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }


    int top() {
        int size = q1.size(), res;
        while (--size) {
            q2.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q2.push(res);
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }


    bool empty() {
        return q1.empty() && q2.empty();
    }

};

int main() {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
    cout << param_4;
}