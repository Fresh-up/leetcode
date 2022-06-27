// 思路：计算两数组的差值数组的最大连续子串和，加上另一个数组即可
class Solution {
public:
    // 连续最大子串和
    long long maxsub(vector<int>& nums) {
        long long pre = 0;
        long long res = 0;
        for (const auto& num : nums) {
            pre = max(num + pre, (long long)num);
            res = max(res, pre);
        }
        return res;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff1(n);
        vector<int> diff2(n);
        int sm1 = 0, sm2 = 0;
        for (int i = 0; i < n; ++i) {
            diff1[i] = nums2[i] - nums1[i];
            diff2[i] = -diff1[i];
            sm1 += nums1[i];
            sm2 += nums2[i];
        }
        sm1 += maxsub(diff1);
        sm2 += maxsub(diff2);

        return max(sm1, sm2);
    }
};