#include <vector>
using namespace std;
//排列回溯的是交换的位置，组合回溯的是是否把当前数字加入到结果中
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }
    void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k){
        if (count == k){
            ans.emplace_back(comb);
            return;
        }
        for (int i = pos; i <= n; ++i){
            comb[count++] = i;//修改当前节点状态
            backtracking(ans, comb, count, i + 1, n, k);//递归子节点i+1
            --count;//回改当前节点状态
        }        
    }
};O(n×n!)   O(n)