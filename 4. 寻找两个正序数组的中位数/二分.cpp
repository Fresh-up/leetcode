// 主要一个思想：比较a[k/2 - 1]和b[k/2 - 1], 可以排除较小的那个的前k/2个元素
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) & 1) {
            return (double)findKth(nums1, nums2, (m + n) / 2 + 1);
        } else {
            return (findKth(nums1, nums2, (m + n) / 2) + findKth(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
        }
    }
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int p1 = 0, p2 = 0, m = nums1.size(), n = nums2.size();
        while (true) {
            if (p1 >= m) return nums2[p2 + k - 1];
            if (p2 >= n) return nums1[p1 + k - 1];
            if (k == 1) return min(nums1[p1], nums2[p2]);

            int i = k / 2 - 1;
            int t1 = min(p1 + i, m - 1);
            int t2 = min(p2 + i, n - 1);
            // if (nums1[t1] >= nums2[t2]) p2 += i + 1;
            // else p1 += i + 1;
            // k -= k / 2;
            if (nums1[t1] >= nums2[t2]) {
                k -= t2 - p2 + 1;
                p2 += i + 1;
            } else {
                k -= t1 - p1 + 1;
                p1 += i + 1;
            }
        }
    }
};
// O(log(m+n)) O(1)