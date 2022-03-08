//
// Created by 倪泽溥 on 2022/1/30.
//
#include "vector"
#include "algorithm"
#include "iostream"
#include "numeric"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2)
            return size;
        vector<int> res(size,1);
        for(int i = 1;i < size;i++){
            if(ratings[i] > ratings[i-1]){
                res[i] = res[i-1]+1;
            }
        }
        for (int i = size-1;i>0;i--){
            if(ratings[i] < ratings[i-1]){
                res[i-1] = max(res[i-1],res[i]+1);
            }
        }
        return accumulate(res.begin(),res.end(),0);

    }
};

int main() {
    Solution solution;
    int b[5] = {1, 0, 2};
    vector<int> rating(b, b + 3);

    int res = solution.candy(rating);
    cout << res;
}