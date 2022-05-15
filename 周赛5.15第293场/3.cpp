// 我们枚举按位与的结果哪一位不是零，那么这一位不是零的所有数都可以参与
// 按位与。选择最多数参与的那一位作为答案即可。
// 复杂度O(nlogA)，其中 A 是 candidates 中的最大值。

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i <= 30; ++i) {
            int t = 0;
            for (int x : candidates) if (x >> i & 1) ++t;
            ans = max(ans, t);
        }
        return ans;
    }
};