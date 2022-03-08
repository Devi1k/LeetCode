//
// Created by 倪泽溥 on 2022/1/30.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty())
            return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), []
                (vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                ++total;
            } else
                prev = intervals[i][1];
        }
        return total;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> M;
    vector<int> N;
    N.push_back(1);
    N.push_back(2);
    M.push_back(N);  //将形第一个内层vector对象N添加到外层vector对象M中
    N.clear();
    N.push_back(1);
    N.push_back(2);
    M.push_back(N);  //将形第一个内层vector对象N添加到外层vector对象M中
    N.clear();
    N.push_back(1);
    N.push_back(2);
    M.push_back(N);  //将形第一个内层vector对象N添加到外层vector对象M中
    N.clear();


    int res = solution.eraseOverlapIntervals(M);
    cout << res;
}