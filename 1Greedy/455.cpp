//
// Created by 倪泽溥 on 2022/1/30.
//
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie = 0, child = 0;
        while (cookie < s.size() && child < g.size()) {
            if (g[child] <= s[cookie]) {
                ++child;
            }
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