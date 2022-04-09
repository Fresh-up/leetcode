#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
[1,1,2]
*/
class Solution {
public:
    vector<int> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int level, vector<int>& perm){
        if (level == nums.size()){
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (vis[i] || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])){
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, level + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }
};
//O(nxn!) O(n)