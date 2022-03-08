//
// Created by 倪泽溥 on 2022/2/11.
//
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string res = "";
        for (string dic: dictionary) {
            int i = 0, j = 0;
            while (i < dic.size() && j < s.size()) {
                if (dic[i] == s[j]) {
                    i++;
                }
                j++;
            }
            if (i == dic.size()) {
                if (dic.size() > res.size() || (dic.size() == res.size() && dic < res))
                    res = dic;
            }
        }
        return res;
    }
};