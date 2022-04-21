//
// Created by 倪泽溥 on 2022/3/14.
//
#include "../head.h"

vector<int> heap;

class heap {
    vector<int> res;
public:
    heap() {

    }

    int top() {
        return res[0];
    }

    void push(int k) {
        res.emplace_back(k);
        swim(res.size() - 1);
    }

    void pop() {
        res[0] = res.back();
        res.pop_back();
        sink(0);
    }

    void swim(int pos) {
        while (pos > 1 && res[pos / 2] < res[pos]) {
            swap(res[pos / 2], res[pos]);
            pos /= 2;
        }
    }

    void sink(int pos) {
        while (2 * pos <= N) {
            int i = 2 * pos;
            if (i < N && res[i] < res[i + 1])
                ++i;
            if (res[pos] >= res[i])
                break;
            swap(res[pos], res[i]);
            pos = i;
        }
    }
};