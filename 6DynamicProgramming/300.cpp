//
// Created by 倪泽溥 on 2022/4/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size(), max_length = 0;
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;

    }
};

int main() {

}
