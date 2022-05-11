class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int summ = accumulate(nums.begin(), nums.end(), 0);
        int twosumm = summ * 2 + 1;
        if (abs(target) > summ) return 0;
        vector<vector<int>> dp(n, vector<int>(twosumm, 0));
        if (nums[0] == 0) dp[0][summ] = 2;// 这里有坑
        else {
            dp[0][summ - nums[0]] = 1;
            dp[0][summ + nums[0]] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = -summ; j <= summ; ++j) {
                // 由于数组索引不能小于0，所以把-summ~summ映射到0~summ*2
                int t = j - nums[i] + summ;
                int s = j + nums[i] + summ;
                if (t >= 0 && t < twosumm) {
                    dp[i][j + summ] += dp[i - 1][t];
                }
                if (s >= 0 && s < twosumm) {
                    dp[i][j + summ] += dp[i - 1][s];
                }
            }
        }
        return dp[n - 1][target + summ];
    }
};
// O(n*twosumm) O(n*twosumm)