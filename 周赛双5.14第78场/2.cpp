class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        long long left = nums[0];
        // 问题在accumulate整数溢出
        // long long right = accumulate(nums.begin(), nums.end(), 0) - left;
        long long right = 0;
        for (const int& num : nums) {
            right += num;
        }
        right -= left;
        for (int i = 1; i < nums.size(); ++i) {
            if (left >= right) ++ret;
            right -= nums[i];
            left += nums[i];
        }
        return ret;
    }
};