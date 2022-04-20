class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, target, candidates, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& temp,
        int target, vector<int>& candidates, int idx){
        if (idx == candidates.size() || target < 0) return;
        if (target == 0){
            res.emplace_back(temp);
            return;
        }
        backtrack(res, temp, target, candidates, idx + 1);
        if (target - candidates[idx] >= 0){
            temp.emplace_back(candidates[idx]);
            backtrack(res, temp, target - candidates[idx], candidates, idx);
            temp.pop_back();
        }
    }
};