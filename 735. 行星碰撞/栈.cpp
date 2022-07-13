class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;
        for (int i = asteroids.size() - 1; i >= 0; --i) {
            if (asteroids[i] > 0) {
                if (stk.empty() || stk.top() > 0) stk.push(asteroids[i]);
                else {
                    while (!stk.empty() && stk.top() < 0 && -stk.top() < asteroids[i]) stk.pop();
                    if (!stk.empty() && -stk.top() == asteroids[i]) {
                        stk.pop();
                        continue;
                    } else if (stk.empty() || stk.top() > 0) stk.push(asteroids[i]);
                }
            } else stk.push(asteroids[i]);
        }
        while (!stk.empty()) {
            ans.emplace_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
// O(n) O(n)