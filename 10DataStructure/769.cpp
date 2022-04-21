//
// Created by 倪泽溥 on 2022/3/10.
//

#include "../head.h"

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int chunk = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = max(cur_max, arr[i]);
            if (cur_max == i)
                ++chunk;
        }
        return chunk;
    }
};