// 每段绳子为3最优，2次之，1最差
// double pow(double a, double b); 求a的b次方
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0) return (int)pow(3, a);
        if (b == 1) return (int)pow(3, a - 1) * 4;
        return (int)pow(3, a) * 2;
    }
};
// O(1) O(1)