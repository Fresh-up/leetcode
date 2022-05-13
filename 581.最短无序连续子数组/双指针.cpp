class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int p = 0, lm = 0;
        int rm = nums.size() - 1;
        if (rm == 0) return 0;
        while (p <= rm && nums[p] >= nums[lm]) lm = p++;
        // 这时,0~lm都是递增
        p = rm;
        while (p >= 0 && nums[p] <= nums[rm]) rm = p--;
        // 这时,rm~n-1都是递增
        if (rm < lm) return 0;
        int mmax = *max_element(nums.begin() + lm, nums.begin() + rm + 1);
        int mmin = *min_element(nums.begin() + lm, nums.begin() + rm + 1);
        while (lm >= 0 && nums[lm] > mmin) --lm;
        while (rm < nums.size() && nums[rm] < mmax) ++rm;
        return rm - lm - 1;
    }
};
// O(n) O(1)