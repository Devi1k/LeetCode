//
// Created by 倪泽溥 on 2022/2/4.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> character(26);
        for (int i = 0; i < s.size(); ++i) {
            character[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            right = max(character[s[i] - 'a'], right);
            if (i == right) {
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = solution.partitionLabels(s);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
    }
}