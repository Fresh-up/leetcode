// 二进制n位的，前面的从0到n-1位的重复
class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> dp(n + 1, 0);
        int j = 1, k = 1, judge = 2;
        while (j <= n) {
            dp[j] = dp[j % k] + 1;
            if (j == judge - 1) {
                judge *= 2;
                k *= 2;
            }
            ++j;
        }
        return dp;
    }
};
// O(n) O(1)