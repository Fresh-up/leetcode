class Solution {
public:
    int totalSteps(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) return 0;
        int ans = 0;
        do {
            vector<int> nset{nums[0]};
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[i - 1]) continue;
                else nset.emplace_back(nums[i]);
            }
            nums = nset;
            ++ans;
        } while (!is_sorted(nums.begin(), nums.end()));
        return ans;
    }
};