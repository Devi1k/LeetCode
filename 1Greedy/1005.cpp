//
// Created by 倪泽溥 on 2022/10/11.
//
#include "vector"
#include "numeric"
#include "iostream"

using namespace std;

class Solution {
private:
    int sum(vector<int> &nums) {
        int sum = 0;
        for (auto &n: nums) {
            sum += n;
        }
        return sum;
    }

    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                --k;
            }
        }
        if (k > 0 && k % 2) nums[nums.size() - 1] *= -1;
        return sum(nums);
    }
};

int main() {
    vector<int> nums = {3, -1, 0, 2};
    Solution solution;
    cout << solution.largestSumAfterKNegations(nums, 3);
}