class Solution {
    vector<int> count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem - 1] != 0) return count[rem - 1];
        int mmin = INT_MAX;
        for (const auto& coin : coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < mmin) mmin = res + 1;
            count[rem - 1] = mmin == INT_MAX ? -1 : mmin;
        }
        return count[rem - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount, 0);
        return dp(coins, amount);
    }
};