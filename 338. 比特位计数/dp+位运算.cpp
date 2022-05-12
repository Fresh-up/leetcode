// 二进制n位的，前面的从0到n-1位的重复
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // 把二进制数右移一位，得到dp值，再判断右移的一位是奇数还是偶数
            // 奇数+1，偶数+0
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
// O(n) O(1)