//
// Created by 倪泽溥 on 2022/3/12.
//

#include "../head.h"

class MinStack {
    stack<int> res, minRes;
public:
    MinStack() {

    }

    void push(int val) {
        res.push(val);
        if (val < minRes.top() || minRes.empty())
            minRes.push(val);
    }

    void pop() {
        int s = res.top();
        if (s == minRes.top() && !minRes.empty())
            minRes.pop();
        res.pop();

    }

    int top() {
        return res.top();
    }

    int getMin() {
        return minRes.top();
    }
};