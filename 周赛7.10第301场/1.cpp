class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[1] == 0) return amount[2];
        int t = amount[0] <= 0 ? amount[1] : amount[1] - amount[0] + 1;
        amount[1] -= t;
        amount[2] -= t;
        return t + fillCups(amount);
    }
};
// 人家的思路：用最大的和两个较小的逐一匹配，这是最优解法
// 当两个较小的之和比最大的大，超出的部分记为t，一定是一个是x，另一个是
// x + 1这才最优，则次数就是(t + 1) / 2

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[0] + amount[1] <= amount[2]) return amount[2];
        else {
            int t = amount[0] + amount[1] - amount[2];
            return (t + 1) / 2 + amount[2];
        }
    }
};