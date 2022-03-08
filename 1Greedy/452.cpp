//
// Created by 倪泽溥 on 2022/2/4.
//


#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end(), []
                (vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });
        int res = 1, pos = points[0][1];
        for (const vector<int> &balloon: points) {
            if (balloon[0] > pos) {
                res++;
                pos = balloon[1];
            }
        }
        return res;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> points;
    vector<int> res;
    res.push_back(1);
    res.push_back(2);
    points.push_back(res);
    res.clear();
    res.push_back(3);
    res.push_back(4);
    points.push_back(res);
    res.clear();
    res.push_back(5);
    res.push_back(6);
    points.push_back(res);
    res.clear();
    res.push_back(7);
    res.push_back(8);
    points.push_back(res);
    res.clear();
    int ans = solution.findMinArrowShots(points);
    cout << ans;
}