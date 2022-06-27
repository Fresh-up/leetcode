class Solution {
public:
    const int MOD = 1000000007;
    int countHousePlacements(int n) {
        vector<pair<long long, long long>> dp(n, pair<long long, long long>{0, 0});
        dp[0].first = 1;
        dp[0].second = 1;
        for (int i = 1; i < n; ++i) {
            dp[i].first = (dp[i - 1].first + dp[i - 1].second) % MOD;
            dp[i].second = dp[i - 1].first;
        }
        long long ans = (dp[n - 1].first + dp[n - 1].second) % MOD;
        return (int)(ans * ans % MOD);
    }
};