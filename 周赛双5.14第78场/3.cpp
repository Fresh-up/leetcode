class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        long long now = 0, ans = 0;
        for (int i = 0, j = 0; j < tiles.size(); ++i) {
            while (j < tiles.size() && tiles[j][1] + 1 - tiles[i][0] <= carpetLen) {
                now += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            if (j < tiles.size()) 
                ans = max(ans, now + max(0, tiles[i][0] + carpetLen - tiles[j][0]));
            else ans = max(ans, now);
            now -= tiles[i][1] - tiles[i][0] + 1;
        }
        return ret;
    }
};