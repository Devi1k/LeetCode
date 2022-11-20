//
// Created by 倪泽溥 on 2022/2/6.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] > b[0] || a[0] == b[0] && a[1] < b[1])
            return true;
        return false;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto p: people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> people;
    vector<int> N;
    int k, m;
    for (int i = 0; i < 6; ++i) {
        cin >> k;
        cin >> m;
        N.push_back(k);
        N.push_back(m);
        people.push_back(N);
        N.clear();
    }
    vector<vector<int>> res = solution.reconstructQueue(people);
    for (const vector<int> re: res) {
        cout << re[0];
        cout << re[1] << endl;
    }
}