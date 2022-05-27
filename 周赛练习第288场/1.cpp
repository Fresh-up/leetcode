class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        string oddstr, evenstr;
        string res;
        for (const char& ss : s) {
            if ((ss - '0') & 1) oddstr += ss;
            else evenstr += ss;
        }
        sort(oddstr.begin(), oddstr.end());
        sort(evenstr.begin(), evenstr.end());
        int odd = oddstr.size() - 1, even = evenstr.size() - 1;
        for (const char& ss : s) {
            if ((ss - '0') & 1) {
                res += oddstr[odd];
                --odd;
            } else {
                res += evenstr[even];
                --even;
            }
        }
        return stoi(res);
    }
};