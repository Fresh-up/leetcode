// 油站的油越多越划算，所以用堆记录，不加参数默认大顶堆
// 如果到不了下一个油站，再从堆里加最大的油
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (stations.empty()) return target > startFuel ? -1 : 0;
        priority_queue<int> q;
        int ans = 0;
        vector<int> vec{stations[0][0]};
        for (int i = 1; i < stations.size(); ++i) {
            vec.emplace_back(stations[i][0] - stations[i - 1][0]);
        }
        vec.emplace_back(target - stations[stations.size() - 1][0]);
        for (int i = 0; i < vec.size(); ++i) {
            startFuel -= vec[i];
            while (startFuel < 0) {
                if (q.empty()) return -1;
                else {
                    startFuel += q.top();
                    q.pop();
                    ++ans;
                }
            }
            if (i < stations.size()) q.push(stations[i][1]);
        }
        return ans;
    }
};
// O(nlogn) 每次加入一个元素到优先队列，内部处理一次用时O(logn)
// O(n)