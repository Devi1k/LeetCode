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
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i) {
            ans += max(0, prices[i + 1] - prices[i]);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> prices;
    int k;
    for (int i = 0; i < 6; ++i) {
        cin >> k;
        prices.push_back(k);
    }
    int res = solution.maxProfit(prices);
    cout << res;
}