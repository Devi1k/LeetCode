//
// Created by 倪泽溥 on 2022/2/6.
//
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int> &a,const vector<int> &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> people;
    vector<int> N;
    int k,m;
    for (int i = 0; i < 6; ++i) {
        cin >> k;
        cin >> m;
        N.push_back(k);
        N.push_back(m);
        people.push_back(N);
        N.clear();
    }
    vector<vector<int>> res = solution.reconstructQueue(people);
    for (const vector<int> re:res) {
        cout << re[0];
        cout << re[1] << endl;
    }
}