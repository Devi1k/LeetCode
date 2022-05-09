#include<vector>
#include<iostream>
#include <map>

using namespace std;

class Solution {
public:
    int getRes(int total, int num, map<int, int> &blood) {
        int res = 0;

        for (auto b: blood) {
            total -= b.first - res;
            if (total) {
                res += b.first - res;
                total += b.second;
            } else
                return res;
        }
        return total + res;
    }


};

int main() {
    int total, nums;
    vector<int> s;
    vector<int> t;
    map<int, int> blood;
    cin >> total;
    cin >> nums;
    int b;
    for (int i = 0; i < nums; ++i) {
        cin >> b;
        s.push_back(b);
    }
    for (int i = 0; i < nums; ++i) {
        cin >> b;
        t.push_back(b);
    }
    for (int i = 0; i < nums; ++i) {
        blood[s[i]] = t[i];
    }
    Solution solution;
    cout << solution.getRes(total, nums, blood);
//    vector<int> res = solution.getRes(num, s);
//    for (auto r: res) {
//        cout << r << endl;
//    }
}


