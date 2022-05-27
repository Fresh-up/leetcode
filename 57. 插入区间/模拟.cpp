class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ll = newInterval[0], rr = newInterval[1];
        vector<vector<int>> ans;
        bool placed = false;
        for (const auto& in : intervals) {
            if (in[0] > rr) {
                // 说明该区间在新区间的右边
                if (!placed) {
                    ans.push_back({ll, rr});
                    placed = true;
                } 
                // 不能添加else,否则第一个没有交集的区间就不能插入
                ans.emplace_back(in);
            }
            else if (in[1] < ll) {
                // 说明该区间在新区间的左边
                ans.emplace_back(in);
            }
            else {
                ll = min(ll, in[0]);
                rr = max(rr, in[1]);
            }
        }
        // 遍历到最后还没有放置新区间，说明新区间在最后并不与给定区间交集
        if (!placed) ans.push_back({ll, rr});
        return ans;
    }
};
// O(n) O(1)