//
// Created by 倪泽溥 on 2022/2/16.
//
#include "vector"

using namespace std;

class Solution {
public:
    bool Search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end) {
            mid = (end - start) / 2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[start]) {
                start++;
            } else if (nums[mid] <= nums[end]) {
                if(target >= nums[mid] && target < nums[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            } else{
                if(target <= nums[mid] && target > nums[start]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};