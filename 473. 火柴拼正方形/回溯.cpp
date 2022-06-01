class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int each = total >> 2;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return backtrack(0, matchsticks, edges, each);
    }
    bool backtrack(int index, vector<int>& matchsticks, vector<int> &edges, int len) {
        if (index == matchsticks.size()) return true;
        for (int i = 0; i < 4; ++i) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && backtrack(index + 1, matchsticks, edges, len)) 
                return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};
// O(4^n) O(n)