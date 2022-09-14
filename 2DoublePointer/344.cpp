//
// Created by zepu.ni on 2022/8/30.
//
//
// Created by zepu.ni on 2022/8/30.
//
# include "vector"
# include "iostream"

using namespace std;

class Solution {
public:
    int reverseString(vector<char> &s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

int main() {
    Solution solution;
    vector<char> nums = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(nums);
    for (auto s: nums) {
        cout << s;
    }
}