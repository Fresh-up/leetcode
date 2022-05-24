// 大数越界：可以把乘方拆开，一次次乘，每次乘同时取余
class Solution {
public:
    int cuttingRope(int n) {
        const int MOD = 1000000007;
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        long long res = 1;
        for (int i = 1; i < a; ++i) {
            res = 3 * res % MOD;
        }
        if (b == 0) return (int)(res * 3 % MOD);
        if (b == 1) return (int)(res * 4 % MOD);
        return (int)(res * 6 % MOD);
    }
};