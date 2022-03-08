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
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
int main() {
    Solution solution;
    string s = "ababcbacabdefegdehijhklij";
    vector<int> res= solution.partitionLabels(s);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] ;
    }
}