class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        int j = s.size() - 1;

        while (i >= 0 && s[i] >= s[i + 1]) --i;
        if (i == -1) return -1;
        while (j >= 0 && s[j] <= s[i]) --j;
        swap(s[i], s[j]);
        string sub = s.substr(i + 1);
        sort(sub.begin(), sub.end());
        long long ans = stoll(s.substr(0, i + 1) + sub);
        if (ans > INT_MAX) return -1;
        else return (int)ans;
    }
};
// O(logn) O(logn)