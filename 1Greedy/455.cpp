//
// Created by 倪泽溥 on 2022/1/30.
//
#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie])
                ++child;
            ++cookie;
        }
        return child;
    }
};


int main() {
    Solution solution;
    int b[5] = {1, 2, 3, 4};
    vector<int> children(b, b + 2);
    vector<int> cookie(b, b + 3);

    int res = solution.findContentChildren(children, cookie);
    cout << res;
}