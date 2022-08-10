class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (const auto& c : s) {
            int t = c - 'a', m = 0;
            for (int j = 0; j < 26; ++j) 
                if (abs(t - j) <= k) m = max(m, dp[j] + 1);
            dp[t] = max(dp[t], m);
        }
        return *max_element(dp.begin(), dp.end());
    }
};