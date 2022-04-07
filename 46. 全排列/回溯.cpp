#include <vector>
using namespace std;

/*回溯法：一种通过探索所有可能的候选解来找出所有的解的算法。
如果候选解被确认不是一个解（或者至少不是最后一个解），
回溯算法会通过在上一步进行一些变化抛弃该解，即回溯并且再次尝试。
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
        if(level == nums.size() - 1){
            ans.emplace_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); ++i){
            //把已选的都放在左边，未选的都放在右边，想象有一个分隔符
            swap(nums[i], nums[level]);
            backtracking(nums, level+1, ans);
            swap(nums[i], nums[level]);//选完后回归原样，准备换一个数字，再选
        }
    }
};//O(n×n!)     O(n)