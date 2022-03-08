class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return (subString(left + 1, right, s) || subString(left, right - 1, s));
                left++, right++;
            }
        }
        return true;
    }

private:
    bool subString(int l, int r, string s) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};