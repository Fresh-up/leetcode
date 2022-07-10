class Solution {
public:
    bool canChange(string start, string target) {
        int s = 0, t = 0, n = start.size();
        while (t < n) {
            if (target[t] == '_') {
                ++t;
                continue;
            } else if (target[t] == 'L') {
                while (s < n && start[s] == '_') ++s;
                if (s >= n || start[s] == 'R' || s < t) return false;
                else {
                    ++s;
                    ++t;
                }
            } else {
                while (s < n && start[s] == '_') ++s;
                if (s >= n || start[s] == 'L' || s > t) return false;
                else {
                    ++s;
                    ++t;
                }
            }
        }
        while (s < n) {
            if (start[s] == '_') ++s;
            else return false;
        }
        return s == n;
    }
};