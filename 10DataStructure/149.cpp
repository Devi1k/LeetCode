//
// Created by 倪泽溥 on 2022/3/17.
//

#include "../head.h"

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        unordered_map<double, int> hash;
        int max_count = 0, same = 1, same_y = 1;
        for (int i = 0; i < points.size(); ++i) {
            same = 1, same_y = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][1] == points[j][1]) {
                    // 斜率为0，同一列
                    ++same_y;
                    if (points[i][0] == points[j][0]) {
                        // 相同点
                        ++same;
                    }
                } else {
                    double dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
                    ++hash[dx / dy];
                }
            }
            max_count = max(max_count, same_y);
            for (auto item: hash) {
                max_count = max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};

int main() {
    vector<vector<int>> points = {
            {1, 1},
            {3, 2},
            {5, 3},
            {4, 1},
            {2, 3},
            {1, 4}
    };
    Solution solution;
    cout << solution.maxPoints(points);

}