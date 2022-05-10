class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 快慢指针, floyd判圈法
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// O(n) O(1)
// Floyd判圈法时间复杂度都是 O(n)
// 注意：该方法一定是要在圈外的节点进入，
// 此题下标0不在范围内，所以一定是圈外