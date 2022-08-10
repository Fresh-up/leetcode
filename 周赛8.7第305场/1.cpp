class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int t = diff + nums[i];
            int j = i + 1;
            while (j < nums.size() && nums[j] < t) ++j;
            if (j == nums.size() || nums[j] > t) continue;
            else t = diff + nums[j++];
            while (j < nums.size() && nums[j] < t) ++j;
            if (j == nums.size() || nums[j] > t) continue;
            else ++ans;
        }
        return ans;
    }
};

// 哈希表
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        int ans = 0;
        for (const auto& num : nums) st.insert(num);
        for (const auto& num : nums) {
            if (st.count(num - diff) && st.count(num + diff))
                ++ans;
        }
        return ans;
    }
};
// O(n) O(n)