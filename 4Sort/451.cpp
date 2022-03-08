//
// Created by 倪泽溥 on 2022/3/1.
//
#include "../head.h"

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        int max_freq = 0;
        int length = s.size();
        for (const char &ch: s) {
            max_freq = max(max_freq, ++counts[ch]);
        }
        vector<string> buckets(max_freq + 1);
        for (const auto &p: counts) {
            buckets[p.second].push_back(p.first);
        }
        string ans;
        for (int i = max_freq; i > 0; --i) {
            string &bucket = buckets[i];
            for (auto &ch: bucket) {
                for (int k = 0; k < i; ++k) {
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};


int main() {
    string s = "";
    cin >> s;
    Solution solution;
    cout << solution.frequencySort(s) << endl;
    return 0;
}