//
// Created by 倪泽溥 on 2022/2/6.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        if (nums.size() == 1)
            return true;
        bool flag = nums[1] > nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i+1]){
                if (!flag) {
                    if (nums[i + 1] >= nums[i - 1]) {
                        nums[i] = nums[i + 1];
                    } else
                        nums[i + 1] = nums[i];
                    flag = true;
                }else
                    return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> num;
    int k;
    for (int i = 0; i < 3; ++i) {
        cin >> k;
        num.push_back(k);
    }
    bool res = solution.checkPossibility(num);
    cout << res;
}
