//
// Created by zepu.ni on 2022/9/23.
//
#include "stack"
#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto ch: s) {
            if (!res.empty() && res.back() == ch) {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.removeDuplicates("abbaca");
}