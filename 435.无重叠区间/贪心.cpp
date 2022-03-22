#include <vector>
#include <algorithm>
using namespace std;
//intervals[i] = [start, end],返回需要移除区间的最小数量
//使得剩余区间不重叠
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int pick = 1, n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int fin = intervals[0][1];
        for (int i = 1; i < n; ++i){
            if (fin <= intervals[i][0]){
                ++pick;
                fin = intervals[i][1];
            }
        }
        return n - pick;
    }
};