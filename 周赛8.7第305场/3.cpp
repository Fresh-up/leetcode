class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // [划分]->子问题->dp
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        // dp[i]表示nums[0]~nums[i-1]是否可划分
        dp[0] = true;// 空表示已经划分好了
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            if (dp[i - 1] && x == nums[i - 1]) dp[i + 1] = true;
            else if (i > 1 && dp[i - 2]) {
                if (x == nums[i - 1] && x == nums[i - 2])
                    dp[i + 1] = true;
                else if (x == nums[i - 1] + 1 && x == nums[i - 2] + 2)
                    dp[i + 1] = true;
            }
        }
        return dp[n];
    }
};
// O(n) O(n)