#include<vector>
#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 3 2 4 1 5
    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int i = l, j = r, key = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= key) --j;
            nums[i] = nums[j];
            while (i < j && nums[i] <= key) ++i;
            nums[j] = nums[i];
        }
        nums[i] = key;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }

};

int main() {
    Solution solution;
    vector<int> nums = {9, 10, 4, 0, 9};
    solution.quick_sort(nums, 0, nums.size() - 1);
    for (auto n: nums) {
        cout << n << " ";
    }
}


