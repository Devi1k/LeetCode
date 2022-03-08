//
// Created by 倪泽溥 on 2022/2/7.
//
#include "iostream"
#include "vector"

using namespace std;;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum = 0;
//        vector<int> res;
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum < target) {
                l++;
            } else if (sum > target)
                --r;
            else
                break;
        }
        return vector<int>{l + 1, r + 1};
    }
};

int main() {
    vector<int> numbers;
    int k;
    for (int i = 0; i < 3; ++i) {
        cin >> k;
        numbers.push_back(k);
    }
    Solution solution;
    vector<int> res = solution.twoSum(numbers, 6);
    for (int re: res) {
        cout << re << ",";
    }
}
