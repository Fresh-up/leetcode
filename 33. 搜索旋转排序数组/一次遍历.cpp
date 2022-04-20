class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] < target){
            int l = 1;
            while (l < nums.size() && nums[l] > nums[l - 1]){
                if (nums[l] == target) return l;
                ++l;
            }
            return -1;
        }
        else if (nums[0] > target){
            // 从后面搜索
            int r = nums.size() - 2;
            if (nums[r + 1] == target) return r + 1;
            while (r >= 0 && nums[r] < nums[r + 1]){
                if (nums[r] == target) return r;
                --r;
            }
            return -1;
        }
        else return 0;
    }
};

// 最坏的情况是O(n) 