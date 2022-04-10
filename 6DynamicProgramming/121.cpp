//
// Created by 倪泽溥 on 2022/4/9.
//

# include "../head.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sell = 0, buy = INT_MIN;
        for (int price: prices) {
            buy = max(buy, -price);
            sell = max(sell, buy + price);
        }
        return sell;
    }
};


int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    cout << solution.maxProfit(prices);
}