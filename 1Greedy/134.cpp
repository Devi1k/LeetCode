//
// Created by 倪泽溥 on 2022/11/11.
//
#include "vector"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int minSquare = INT_MAX;
        int res = 0, square = 0;
        for (int i = 0; i < gas.size(); ++i) {
            square += gas[i] - cost[i];
            if (square < minSquare) {
                minSquare = square;
                res = i;
            }
        }
        return square < 0 ? -1 : (res + 1) % gas.size();
    }
};