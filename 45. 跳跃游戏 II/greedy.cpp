#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        // [2,3,1,1,4]
        // 思路：在选了一个之后，根据这个能到达的范围，选择这范围里面能达到最远距离的那个
        if (nums.size() == 1) return 0;
        int ans = 1;
        reach(nums, ans, nums[0], 0);
        return ans;
        
    }
    void reach(vector<int>& nums, int& ans, int far, int prex){
        if (far >= nums.size() - 1) return;
        bool flag = false;
        int maxreach = far, pre = prex;
        for (int j = pre + 1; j <= far; ++j){
            if (nums[j] + j > maxreach){
                maxreach = nums[j] + j;
                prex = j;
                flag = true;
            }
        }
        if (flag) ++ ans;
        reach(nums, ans, maxreach, pre);
    }
};
//O(n) O(1)