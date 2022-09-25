//
// Created by 倪泽溥 on 2022/9/25.
//
#include "stack"
#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int ele1, ele2, temp;
        for (auto const &ch: tokens) {
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                ele1 = st.top();
                st.pop();
                ele2 = st.top();
                st.pop();
                if (ch == "+") {
                    temp = ele1 + ele2;
                } else if (ch == "-") {
                    temp = ele2 - ele1;
                } else if (ch == "*") {
                    temp = ele1 * ele2;
                } else {
                    temp = ele2 / ele1;
                }
                st.push(temp);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};


int main() {
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    Solution solution;
    cout << solution.evalRPN(tokens);
}