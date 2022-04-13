#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            //为什么是小于n-1,因为如果计算最后一个节点的话，可能步骤就会加一
            //maxpos是最大可达位置
            if (maxPos >= i) 
                maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                //因为i是一个一个遍历来的，所以一定会达到前一次跳的终点end
                //然后end成为下一次跳的终点
                //步骤加一,妙!
                end = maxPos;
                ++step;
            }
        }
        return step;
    }
};
//不用递归，快一些，但是一些细节很难想到