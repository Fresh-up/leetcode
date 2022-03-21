#include <vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int cnt = 0;
        int flag = 0;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                l = mid - 1;
                r = mid;
                flag = 1;
                break;
            }
            if (nums[mid] < target){
                l = mid + 1;
            }
            if (nums[mid] > target){
                r = mid - 1;
            }
        }
        if (flag){
            while(l >= 0 && nums[l] == target){
                ++cnt;
                --l;
            }
            while(r < nums.size() && nums[r] == target){
                ++cnt;
                ++r;
            }
            return cnt;
        }
        else return 0;
    }
};