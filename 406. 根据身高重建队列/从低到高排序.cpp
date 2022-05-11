class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, 
            const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });// 按第一个元素升序，第二个元素降序
        int n = people.size();
        vector<vector<int>> res(n);// 先构造n个空位
        for (const auto& person : people) {
            // 每个人在res里面的位置应该是前面若干个满的位置和若干个空位
            int empcnt = person[1] + 1;// 这个person属于第empcnt个空位
            for (int i = 0; i < n; ++i) {
                if (res[i].empty()) {
                    --empcnt;
                    if (empcnt == 0) {
                        res[i] = person;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
// O(n^2) O(logn)排序需要使用栈空间