// 空间优化
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums[0];
        int maxpre = nums[0], minpre = nums[0];
        int maxcurr, mincurr;
        for (int i = 1; i < nums.size(); ++i){
            maxcurr = max(maxpre * nums[i], max(nums[i], minpre * nums[i]));
            mincurr = min(minpre * nums[i], min(nums[i], maxpre * nums[i]));
            m = max(maxcurr, m);
            maxpre = maxcurr;
            minpre = mincurr;
        }
        return m;
    }
};
// O(n) O(1)