class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, start = nums[0];
        for (const int& num : nums) {
            if (num - start > k) {
                start = num;
                ++ans;
            }
        }
        return ans;
    }
};