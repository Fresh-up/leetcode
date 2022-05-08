class Solution {
    const int MOD = 1000000007;
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<long long> f(n + 1, 0), g(n + 1, 0);
        f[0] = 1, g[0] = 1;
        // f[i] 表示连续i个字符，最多三个一组，有多少种搭配
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3 && j <= i; ++j) f[i] = (f[i - j] + f[i]) % MOD;
            for (int j = 1; j <= 4 && j <= i; ++j) g[i] = (g[i - j] + g[i]) % MOD;
        }

        int cnt = 0;
        char last = 0;
        long long ans = 1;
        for (char c : pressedKeys) {
            if (c != last) {
                if (last == '7' || last == '9') ans = ans * g[cnt] % MOD;
                // 不能写成ans *= g[cnt] % MOD;这样会导致ans没有取余
                else ans = ans * f[cnt] % MOD;
                cnt = 0;
                last = c;
            }
            ++cnt;
        }
        if (last == '7' || last == '9') ans = ans * g[cnt] % MOD;
        else ans = ans * f[cnt] % MOD;
        return ans;
    }
};
// O(n) O(n)