//
// Created by 倪泽溥 on 2022/3/1.
//
#include "unordered_map"
#include "vector"
#include "queue"
#include "iostream"

using namespace std;

class Solution {
public:
    class my_comparison {
    public:
        bool operator()(const pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

//    vector<int> topKFrequent(vector<int> &nums, int k) {
//        unordered_map<int, int> hash;
//        vector<int> res(k);
//        for (auto &n: nums) {
//            ++hash[n];
//        }
//        priority_queue<pair<int, int>, vector<pair<int, int>>, my_comparison> pri_que;
//        for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
//            pri_que.push(*it);
//            if (pri_que.size() > k) {
//                pri_que.pop();
//            }
//        }
//        for (int i = k - 1; i >= 0; --i) {
//            res[i] = pri_que.top().first;
//            pri_que.pop();
//        }
//        return res;
//    }
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        int max_count = 0;
        for (auto &n: nums) {
            max_count = max(max_count, ++map[n]);
        }
        vector<vector<int>> count(max_count + 1);
        for (auto &p: map) {
            count[p.second].push_back(p.first);
        }
        vector<int> res;
        for (int i = count.size() - 1; i >= 0; --i) {
            if (count[i].empty())
                continue;
            for (auto &c: count[i]) {
                res.push_back(c);
            }
            if (res.size() == k) {
                break;
            }
        }
        return res;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 4};
    int k = 2;
    vector<int> ans = solution.topKFrequent(nums, k);

    cout << endl;
    return 0;
}