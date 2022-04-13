#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& x, const int& y){
            //记得用const int &常量引用，会快一点
            //假设x是11，y是133
            long sx = 10, sy = 10;
            while (sx <= x) sx *= 10;//sx=100
            //别忘了小于 等于
            while (sy <= y) sy *= 10;//sy=1000
            return sy * x + y > sx * y + x;//11000+133 > 13300+11
            //能想出这方法的也是厉害
        });
        if (nums[0] == 0)
            return "0";
        string ans;
        for (auto &x : nums){
            ans.append(to_string(x));
        }
        return ans;
    }
};
//时间复杂度：O(n \log n \log m)O(nlognlogm)，其中 nn 是给定序列的长度，mm 是 3232 位整数的最大值，
//每个数转化为字符串后的长度是 O(\log m)O(logm) 的数量级。
//排序比较函数的时间复杂度为 O(\log m)O(logm)，共需要进行 O(n \log n)O(nlogn) 次比较。
//同时我们需要对字符串序列进行拼接，时间复杂度为 O(n \log m)O(nlogm)，
//在渐进意义上小于 O(n \log n \log m)O(nlognlogm)。

//O(logn)