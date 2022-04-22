class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0') {
                f[i] += f[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};
// O(n) O(n)
// 我也知道用动态规划，但是困惑我的点在于不会怎么写出for循环里面的内容

// 还可以空间优化
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int b = 1, a = 0, c = 0;
        for (int i = 1; i <= n; ++i) {
            a = 0;
            if (s[i - 1] != '0') {
                a += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                a += c;
            }
            c = b;
            b = a;
        }
        return a;
    }
};