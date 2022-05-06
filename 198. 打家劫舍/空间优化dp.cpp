class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        int pre = nums[0];
        int cur = max(nums[0], nums[1]);
        int tmp;
        for (int i = 2; i < n; ++i){
            tmp = cur;
            cur = max(pre + nums[i], cur);
            pre = tmp;
        }
        return cur;
    }
};