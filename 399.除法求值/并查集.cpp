class Solution {
public:
    // 查找父节点，顺便路径压缩
    int findf(vector<int>& f, vector<double>& w, int x) {
        if (f[x] != x) {
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];// x的父节点改变，x权值变更
            f[x] = father;// 路径压缩
        }
        return f[x];
    }
    // 两个节点不在同一个联通分支，合并，让它们的父节点呈父子关系
    void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        f[fx] = fy;// fx的父节点变更为fy
        w[fx] = val * w[y] / w[x];// fx父节点变更了，权值也要变更
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
            vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;
        // 哈希表的作用：把所有字符串编号存储

        int n = equations.size();
        for (int i = 0; i < n; i++) {// 遍历equations,塞入哈希表
            if (!variables.count(equations[i][0])) {
                variables[equations[i][0]] = nvars++;
            }
            if (!variables.count(equations[i][1])) {
                variables[equations[i][1]] = nvars++;
            }
        }
        vector<int> f(nvars);// 父节点列表
        vector<double> w(nvars, 1.0);// 权重
        for (int i = 0; i < nvars; i++) {
            f[i] = i;
        }// 并查集初始化，每个都是一个联通分支

        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            merge(f, w, va, vb, values[i]);
            // 构建并查集，构造出来的并查集只有一个联通分支，而且只有两层
        }

        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.count(q[0]) && variables.count(q[1])) {
                int ia = variables[q[0]], ib = variables[q[1]];
                int fa = findf(f, w, ia), fb = findf(f, w, ib);
                if (fa == fb) {
                    result = w[ia] / w[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};
// O(ML+N+MlogN+Q(L+logN)) O(NL)