// "一个桶可以放4个"
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t(26, 0);
        int k = tasks.size();
        for (const char& task : tasks) ++t[task - 'A'];
        sort(t.begin(), t.end(), greater<int>());
        int cnt = 1;
        while (cnt < t.size() && t[cnt] == t[0]) ++cnt;
        return max(k, (n + 1) * (t[0] - 1) + cnt);
    }
};
// O(nlogn) O(1)