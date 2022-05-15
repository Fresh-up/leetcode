class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int mmax = special[0] - bottom;
        int cur = mmax;
        for (int i = 1; i < special.size(); ++i) {
            cur = special[i] - special[i - 1] - 1;
            mmax = max(mmax, cur);
        }
        return max(mmax, top - special[special.size() - 1]);
    }
};