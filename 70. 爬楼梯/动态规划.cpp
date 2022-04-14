class Solution {
public:
    int climbStairs(int n) {
        // f(x) = f(x-1) + f(x-2) f(x)只与这两项有关，所以可以用滚动数组
        int p = 0, q = 0, r = 1;
        // r才是每一级想要的，一开始从第一级到最后一级，r才是结果
        for(int i = 1; i <= n; ++i){
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};