class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && !isalnum(s[l])) ++l;
        if (l > r) return true;
        while (l <= r) {
            while (l < r && !isalnum(s[l])) ++l;// 没用l <= r，防止"a a"的情况
            while (l < r && !isalnum(s[r])) --r;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};