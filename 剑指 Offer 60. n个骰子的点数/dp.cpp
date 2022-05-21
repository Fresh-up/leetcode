class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0/6.0);
        for (int i = 2; i <= n; ++i) {
            vector<double> tmp(i * 5 + 1);
            for (int j = 0; j < dp.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    // 正向递推，防止数组越界
                    tmp[j + k] += dp[j] / 6;
                }
            }
            dp = tmp;
        }
        return dp;
    }
};
// O(n^2) O(n)
// 分析技巧：学会用二元函数构造递推公式；反向递推越界，可以用正向递推