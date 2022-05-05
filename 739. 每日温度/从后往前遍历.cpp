// 因为最后一个元素是确定的，所以从后往前遍历；在遍历一个元素时，
// 利用答案的特性可以跳着往后找大于该元素的值
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; --i){
            if (temperatures[i] < temperatures[i + 1])
                res[i] = 1;
            else {
                judge(i, n, i + res[i + 1] + 1, temperatures, res); 
            }
        }
        return res;
    }
    void judge(int i, int n, int j, vector<int>& temperatures, vector<int>& res){
        if (temperatures[i] < temperatures[j]) {
            res[i] = j - i;
            return;
        }
        else {
            if (res[j] == 0) res[i] = 0;
            else judge(i, n, j + res[j], temperatures, res);
        }
    }
};
// 最坏情况是递减序列，O(n^2)，空间复杂度O(n)取决于递归的深度