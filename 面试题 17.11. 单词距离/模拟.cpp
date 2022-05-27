class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int w1 = -1, w2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                w1 = i;
                if (w2 != -1) res = min(res, w1 - w2);
            }
            else if (words[i] == word2) {
                w2 = i;
                if (w1 != -1) res = min(res, w2 - w1);
            }
        }
        if (res == INT_MAX) return words.size();
        return res;
    }
};
// O(n) O(1)