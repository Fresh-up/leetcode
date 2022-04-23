class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0;
        while (r != n){
            if (nums[l] == nums[r]){
                ++cnt;
                if (cnt > 2) nums[r] = INT_MAX;
            }
            else l = r, cnt = 1;
            ++r;
        }
        sort(nums.begin(), nums.end());
        auto ll = lower_bound(nums.begin(), nums.end(), INT_MAX);
        nums.erase(ll, nums.end());
        return nums.size();
    }
};
// O(nlogn) O(1)