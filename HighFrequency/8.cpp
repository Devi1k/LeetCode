

#include <string>
#include "unordered_map"

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, flag = 1, i = 0;
        while (str[i] == ' ') {
            ++i;
        }
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            flag = -1;
            ++i;
        }
        while (i < str.size() && str[i] <= '9' && str[i] >= '0') {
            int digit = str[i] - '0';
            if (ans > INT_MAX / 10) {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            if (ans == INT_MAX / 10 && flag > 0 && digit >= INT_MAX % 10) {
                return INT_MAX;
            }
            if (ans == INT_MAX / 10 && flag < 0 && digit >= flag * (INT_MIN % 10)) {
                return INT_MIN;
            }
            ans = 10 * ans + digit;
            i += 1;
        }
        return ans * flag;
    }
};


int main() {

}
