class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(n + 1, vector<int>(forget, 0));
        dp[1][0] = 1;
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = delay - 1; j < forget - 1; ++j) 
                dp[i][0] = (dp[i - 1][j] + dp[i][0]) % MOD;
                
            for (int j = 1; j < forget; ++j) 
                dp[i][j] = dp[i - 1][j - 1];
        }
        for (int j = 0; j < forget; ++j) 
            ans = (ans + dp[n][j]) % MOD;
        return ans;
    }
};
// O(n) O(n*f) f是forget.size()
// 取模MOD,目的是让每个数都小于MOD，两数相加最大也是20,0000,0014
// 比INT_MAX小，所以a=(b+c)%MOD;中(b+c)不会溢出

// 空间优化版O(f), f是forget.size()
class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> vec(forget, 0);
        vec[0] = 1;
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            vector<int> tmp(forget, 0);
            for (int j = delay - 1; j < forget - 1; ++j) {
                tmp[0] = (vec[j] + tmp[0]) % MOD;
            }
                
            for (int j = 1; j < forget; ++j) 
                tmp[j] = vec[j - 1];
            vec = tmp;
        }
        for (int j = 0; j < forget; ++j) 
            ans = (ans + vec[j]) % MOD;
        return ans;
    }
};