// 把flowers[i]看成是将区间[starti, endi]上的每个时间点都增加一朵花。
// 那么对于第i个人，我们就需要计算出persons[i]时间点上有多少朵花。
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // 第一步先把区间集合用键值对集合表示
        map<int, int> diff;
        // 左闭右开的区间，方便后面用小于等于号判断人是否在区间内
        for (auto i : flowers){
            ++diff[i[0]];
            --diff[i[1] + 1];
        }

        // 第二步把persons的下标和值分离
        // 然后按值排序，这样可以在遍历persons的同时，按序遍历diff
        int n = persons.size();
        vector<int> id(n);// id用来记录观赏者person的下标
        iota(id.begin(), id.end(), 0);// STL,从0开始默认加一
        sort(id.begin(), id.end(), [&](int i, int j){
            return persons[i] < persons[j];
        });// 还能这样用

        // 第三步遍历persons和diff，填入答案
        vector<int> ans(n);
        auto it = diff.begin();
        int sum = 0;
        for (auto i : id){
            // 每次遍历都没有重置sum和it,因为persons的idx和值已经分离
            while (it != diff.end() && it->first <= persons[i])
                sum += it++->second;
            ans[i] = sum;
        }

        return ans;
    }
};
// O(nlogn + mlogm)

/*
总结：
1. 把区间按键值对的形式表示，放入map中
2. 数组下标和值分离，以值的大小对下标排序
*/