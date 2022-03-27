#include "../head.h"

class Solution {
private:
    vector<pair<int, int>> freq;
//    unordered_map<int, int> freq;
    vector<vector<int>> ans;
    vector<int> sequence;
public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.emplace_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }
        dfs(pos + 1, rest);
        // 至多出现的次数（rest/freq[pos].first代表最多出现的次数，second代表实际出现的次数）
        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.emplace_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }

};


int main() {
    Solution solution;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = solution.combinationSum2(candidates, 8);
    for (auto r: res) {
        for_each(r.begin(), r.end(), show_num);
        cout << endl;
    }
}