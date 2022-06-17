class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for (auto& a : arr) {
            if (!q.empty()) {
                q.push(a);
                if (a == 0) q.push(0);
                a = q.front();
                q.pop();
            } else if (a == 0) q.push(0);
        }
    }
};
// O(n) O(n)