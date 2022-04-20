class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (target == nums[mid]) return mid;
            if (nums[0] <= nums[mid]){
                if (target >= nums[0] && target < nums[mid])
                    // 判断别忘了等号
                    r = mid - 1;
                else l = mid + 1;
            }
            else {
                if (target <= nums[nums.size() - 1] && target > nums[mid])
                    // 判断别忘了等号
                    l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

// O(logn) 二分查找，保证一半是有序的