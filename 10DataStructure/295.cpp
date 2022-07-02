//
// Created by 倪泽溥 on 2022/5/28.
//

#include "../head.h"

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};


int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(5);
    medianFinder.addNum(2);
    medianFinder.addNum(1);
    medianFinder.addNum(6);
    cout << medianFinder.findMedian();
}


