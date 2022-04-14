//
// Created by 倪泽溥 on 2022/4/13.
//

#include "../head.h"

class Solution {
public:
    unordered_map<int, vector<int>> mp;

    vector<int> beautifulArray(int n) {
        vector<int> ans;
        if (n == 1) {
            ans.push_back(1);
            return ans;
        }
        if (mp.count(n))
            return mp[n];
        int odd_num = (n + 1) / 2;
        int even_num = n / 2;
        vector<int> left = beautifulArray(odd_num);
        vector<int> right = beautifulArray(even_num);
        for (auto l: left) {
            ans.push_back(2 * l + 1);
        }
        for (auto r: right) {
            ans.push_back(2 * r);
        }
        mp[n] = ans;
        return ans;
    }
};
