//
// Created by 倪泽溥 on 2022/3/18.
//
#include "../head.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> ans;
        if (tickets.empty()) {
            return ans;
        }
        unordered_map<string, multiset<string>> hash;
        for (const auto &ticket: tickets) {
            hash[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFK");
        while (!s.empty()) {
            string next = s.top();
            if (hash[next].empty()) {
                ans.push_back(next);
                s.pop();
            } else {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<string>> tickets = {
            {"JFK", "SFO"},
            {"JFK", "ATL"},
            {"SFO", "ATL"},
            {"ATL", "JFK"},
            {"ATL", "SFO"}
    };
    Solution solution;
    vector<string> res = solution.findItinerary(tickets);
    for_each(res.begin(), res.end(), show_string);
}