#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getRes(int num, vector<string> &s) {
        vector<int> res;
        for (int i = 0; i < num; ++i) {
            res.push_back(minReturnStr(s[i]));
        }
        return res;
    }


    int minReturnStr(string s) {
        int length = s.size();
        string t = string(s.rbegin(), s.rend());
        vector<vector<int>> dp(length + 1, vector<int>(length + 1));


        for (int i = 1; i <= length; i++)
            for (int j = 1; j <= length; j++)
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return length - dp[length][length];


    }

};

int main() {
    int num;
    vector<string> s;
    string str;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> str;
        s.push_back(str);
    }
    Solution solution;
    vector<int> res = solution.getRes(num, s);
    for (auto r: res) {
        cout << r << endl;
    }
}


