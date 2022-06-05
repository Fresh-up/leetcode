class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        n >>= 1;
        vector<int> newnums(n);
        for (int i = 0; i < n; ++i) {
            newnums[i] = i & 1 ? max(nums[2*i], nums[2*i + 1]) : min(nums[2*i], nums[2*i + 1]);
        }
        return minMaxGame(newnums);
    }
};