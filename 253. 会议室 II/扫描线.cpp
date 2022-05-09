class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> p;
        for (const vector<int>& i : intervals) {
            p.emplace_back(make_pair(i[0], 1));
            p.emplace_back(make_pair(i[1], -1));
        }
        // 对pair进行sort，当first相同时，按second升序排列
        // 这也是符合预期的，下车就应该在上车之前，这样车上的人才可以最少
        sort(p.begin(), p.end());
        int ret = 0, cur = 0;
        for (const auto& pp : p) {
            cur += pp.second;
            ret = max(ret, cur);
        }
        return ret;
    }
};
// O(nlogn) O(n)