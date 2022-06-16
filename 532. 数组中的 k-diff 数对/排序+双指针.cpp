class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), y = 0, res = 0;
        for (int x = 0; x < n; ++x) {
            if (x != 0 && nums[x] == nums[x - 1]) continue;
            while (y < n && (nums[y] < k + nums[x] || y <= x)) ++y;
            if (y < n && nums[y] == k + nums[x]) ++res;
        }
        return res;
    }
};
// O(nlogn) O(logn)