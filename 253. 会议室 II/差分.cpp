class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> diff(1000001, 0);
        for (const auto& i : intervals) {
            int start = i[0], end = i[1];
            ++diff[start];
            --diff[end];
        }

        for (int i = 1; i < 1000001; ++i) {
            diff[i] += diff[i - 1];
        }
        return *max_element(diff.begin(), diff.end());
    }
};