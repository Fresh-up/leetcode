class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> minheap;
        sort(intervals.begin(), intervals.end());
        minheap.push(intervals[0][1]);
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < minheap.top()) {
                minheap.push(intervals[i][1]);
            } else {
                minheap.pop();
                minheap.push(intervals[i][1]);
            }
        }
        return minheap.size();
    }
};
// O(nlogn) O(n)