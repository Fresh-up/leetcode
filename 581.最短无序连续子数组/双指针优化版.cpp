class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, r = -1;
        int maxn = INT_MIN;
        int minn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (maxn > nums[i]) r = i;// r是当前最右边的错位元素
            else maxn = nums[i];// maxn记录的是访问到i时，前i+1个元素的最大值
            if (minn < nums[n - i - 1]) l = n - i - 1;
            else minn = nums[n - i - 1];
        }
        return r == -1 ? 0 : r - l + 1;
    }
};