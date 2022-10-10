//
// Created by 倪泽溥 on 2022/2/6.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {};
    int res = solution.maxProfit(prices);
    cout << res;
}