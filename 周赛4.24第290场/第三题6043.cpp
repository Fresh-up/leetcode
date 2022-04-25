class Solution {
public:
    // 按横坐标从大到小排序
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[0] > b[0]; });

        int n = points.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) { return points[i][0] > points[j][0]; });

        vector<int> ans(n), cnt(101);
        // 由于纵坐标的高度只有0~100,所以暴力累加即可
        int i = 0;
        for (int id : ids) {
            while (i < rectangles.size() && rectangles[i][0] >= points[id][0])
                ++cnt[rectangles[i++][1]];
            ans[id] = accumulate(cnt.begin() + points[id][1], cnt.end(), 0);
        }
        return ans;
    }
};