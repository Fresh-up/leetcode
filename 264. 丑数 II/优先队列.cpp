class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> myset;
        vector<int> factors{2, 3, 5};
        q.push(1);
        for (int i = 1; i < n; ++i) {
            long long t = q.top();
            q.pop();
            for (int j = 0; j < 3; ++j) {
                long long k = t * factors[j];
                if (!myset.count(k)) {
                    myset.insert(k);
                    q.push(k);
                }
            }
        }
        return q.top();
    }
};
// O(nlogn) O(n)