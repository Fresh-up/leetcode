class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, unordered_set<int>> mp;
        for (const auto& edge : edges) {
            mp[edge[0]].insert(edge[1]);
            mp[edge[1]].insert(edge[0]);
        }
        unordered_set<int> st{0};
        // 可以把res当作已被访问的元素集合从而省略集合st
        unordered_set<int> res;
        for (const auto& rest : restricted) res.insert(rest);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto it = mp[t].begin(); it != mp[t].end(); ++it)
                if (!st.count(*it) && !res.count(*it)) {
                    q.push(*it);
                    st.insert(*it);
                }
        }
        return st.size();
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // 建图，无向图
        unordered_map<int, vector<int>> mp;
        for (const auto& edge : edges) {
            mp[edge[0]].emplace_back(edge[1]);
            mp[edge[1]].emplace_back(edge[0]);
        }
        int ans = 0;
        unordered_set<int> st(restricted.begin(), restricted.end());
        function<void(int, int)> dfs = [&](int x, int fa) {
            // fa是x的父节点
            if (st.count(x)) return;
            ++ans;
            for (const auto& e : mp[x]) 
                // 是树，不能往父节点走，否则死循环
                if (e != fa) dfs(e, x);
        };
        dfs(0, -1);
        return ans;
    }
};
// O(n)