class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        unordered_map<int, int> m;
        m[arr[0]] = 0;
        m[arr[1]] = 1;
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for (int i = 2; i < n; ++i) {
            m[arr[i]] = i;
            for (int j = i - 1; j >= 0 && j + 2 > ans; --j) {
                int t = arr[i] - arr[j];
                if (t >= arr[j]) break;
                if (m.count(t)) {
                    int index = m[t];
                    dp[i][j] = max(3, dp[j][index] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};