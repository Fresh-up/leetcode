class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (auto& as : asteroids) {
            bool alive = true;
            while (alive && as < 0 && !st.empty() && st.back() > 0) {
                alive = -as > st.back();
                if (st.back() <= -as) st.pop_back();
            }
            if (alive) st.push_back(as);
        }
        return st;
    }
};