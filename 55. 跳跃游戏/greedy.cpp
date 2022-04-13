#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool flag = true;
        int maxreach = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            if (i > maxreach) {
                flag = false;
                break;
            }
            maxreach = max(maxreach, nums[i] + i);
        }
        return flag;
    }
};