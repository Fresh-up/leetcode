class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a,
            const vector<int>& b){ return a[0] < b[0]; });
        vector<vector<int>> res;
        vector<int> tmp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] <= tmp[1]){
                tmp[1] = max(intervals[i][1], tmp[1]);
            }
            else {
                res.emplace_back(tmp);
                tmp = intervals[i];
            }
        }
        res.emplace_back(tmp);
        return res;
    }
};
// O(nlogn) O(n)