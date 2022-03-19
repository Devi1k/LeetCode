//
// Created by 倪泽溥 on 2022/3/18.
//
#include "../head.h"

class NumArray {
    vector<int> psum;
public:
    NumArray(vector<int> nums) : psum(nums.size() + 1, 0) {
        partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    }

    int sumRange(int i, int j) {
        return psum[j + 1] - psum[i];
    }
};

int main() {
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    auto *numArray = new NumArray(nums);
    cout << numArray->sumRange(0, 2) << " ";
    cout << numArray->sumRange(1, 5);

}
