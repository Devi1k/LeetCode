//
// Created by 倪泽溥 on 2022/3/20.
//
#include "../head.h"

class MyStack {
    queue<int> res;
public:
    MyStack() {

    }

    void push(int x) {
        int n = res.size();
        res.push(x);
        for (int i = 0; i < n; ++i) {
            res.push(res.front());
            res.pop();
        }
    }

    int pop() {
        int x = res.front();
        res.pop();
        return x;
    }

    int top() {
        return res.front();
    }

    bool empty() {
        return res.empty();
    }
};

int main() {
    MyStack *obj = new MyStack();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
}