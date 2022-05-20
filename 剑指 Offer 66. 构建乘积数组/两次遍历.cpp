class Solution {
public:
    // 两次遍历
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(), tmp = 1;
        if (n == 0) return {};
        vector<int> b(n, 1);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] = b[i - 1] * a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            b[i] = b[i - 1] * tmp;
            tmp *= a[i];
        }
        b[0] = tmp;
        return b;
    }
};
// O(n) O(n)