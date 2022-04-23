class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }

    void backtrack(int cur, vector<int>& nums){
        if (cur == nums.size()){
            ans.emplace_back(tmp);
            return;
        }
        tmp.emplace_bacK(nums[cur]);
        backtrack(cur + 1, nums);
        tmp.pop_back();
        backtrack(cur + 1, nums);
    }
};

vector<int> t;
void dfs(int cur, int n) {
    if (cur == n) {
        // 记录答案
        // ...
        return;
    }
    // 考虑选择当前位置
    t.push_back(cur);
    dfs(cur + 1, n, k);
    t.pop_back();
    // 考虑不选择当前位置
    dfs(cur + 1, n, k);
}
// O(nx2^n)  O(n)