// 用一个指针指向0块后的一个元素，另一个指针指向1块后的一个元素
// 一开始p0和p1都在首元素，找到0时，p0与其交换，还要判断交换后的元素是否是1，
// 若是，再交换p1，p0和p1都自增
// 找到1时,直接交换p1，p1自增

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};