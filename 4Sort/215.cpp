//
// Created by 倪泽溥 on 2022/2/28.
//

#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int quickSelect(vector<int> &a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int> &a, int l, int r) {
        // 随机一个索引，+l保证其在l与r之间
        int i = rand() % (r - l + 1) + l;
        // 把随机选择的数作为标志对比
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int> &a, int l, int r) {
        // 快速排序，如果小于标志
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int> &nums, int k) {
//        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


int main() {
    vector<int> nums = {3, 2, 5, 1, 6, 4};
    int k = 2;
    Solution solution;
    cout << solution.findKthLargest(nums, k);
}