//
// Created by 倪泽溥 on 2022/2/4.
//


#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() < 1) return 0;
        int res = 1;
        sort(points.begin(), points.end(), cmp);
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > points[i - 1][1])
                ++res;
            else
                points[i][1] = min(points[i - 1][1], points[i][1]);
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