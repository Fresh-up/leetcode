class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int l = 0, ret = 0;
        string s = to_string(num);
        while (l <= s.size() - k) {
            int t = stoi(s.substr(l, k));
            if ((t != 0) && (num % t == 0)) ++ret;
            ++l;
        }
        return ret;
    }
};