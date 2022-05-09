class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lorder(n, 1), rorder(n, 1);
        lorder[0] = nums[0], rorder[n - 1] = nums[n - 1];
        for (int i = 1, j = n - 2; i < n; ++i, --j) {
            lorder[i] = lorder[i - 1] * nums[i];
            rorder[j] = rorder[j + 1] * nums[j];
        }
        vector<int> ret(n, 1);
        ret[0] = rorder[1];
        ret[n - 1] = lorder[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            ret[i] = lorder[i - 1] * rorder[i + 1];
        }
        return ret;
    }
};
// O(2n) O(3n)