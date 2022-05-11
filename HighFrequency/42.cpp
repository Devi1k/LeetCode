//
// Created by 倪泽溥 on 2022/5/10.
//
#include "vector"
#include "stack"

using namespace std;

class Solution {
    int trap(vector<int> &height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int cur = st.top();
                st.pop();
                if (st.empty())
                    break;
                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                ans += h * (r - l - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
