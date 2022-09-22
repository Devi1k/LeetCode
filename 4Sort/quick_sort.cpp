//
// Created by 倪泽溥 on 2022/2/28.
//
#include "vector"
#include "iostream"

using namespace std;

void quick_sort(vector<int> &nums, int l, int r) {
    if (l + 1 >= r)
        return;
    int first = l, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
    if (l + 1 >= r)
        return;
    int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
            temp[i++] = nums[p++];
        } else {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i) {
        nums[i] = temp[i];
    }
}


void insert_sort(vector<int> &nums, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}


void bubble_sort(vector<int> &nums, int n) {
    bool flag;
    for (int i = 1; i < n; ++i) {
        flag = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void selection_sort(vector<int> &nums, int n) {
    int mid;
    for (int i = 0; i < n - 1; ++i) {
        mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}


int main() {
    vector<int> nums = {3, 5, 7, 2, 1, 6, 4, 8, 9};
    int n = nums.size();
    vector<int> temp(n);
//    4Sort(nums.begin(), nums.end());
    quick_sort(nums, 0, n);
//    merge_sort(nums, 0, n, temp);
//    insert_sort(nums, n);
//    bubble_sort(nums, n);
//    selection_sort(nums, n);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
}