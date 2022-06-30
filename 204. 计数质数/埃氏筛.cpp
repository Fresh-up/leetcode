// 如果x是质数，那么大于x的倍数2x,3x,...一定不是质数
// 0和1不是质数
// 这里找[2,n)的质数的个数
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        // isPrime[i]为true表示i为质数
        // 0和1由于下面枚举没用到，所以不用管
        int ans = 0;// 记录质数的个数
        for (int i = 2; i < n; ++i) {
            // 标记过程仅当i为质数时才进行
            if (isPrime[i]) {
                ++ans;
                if ((long long)i * i < n) {
                    // 从2x开始标记是冗余的，可以从x*x开始标记
                    // 因为2x,3x...这些一定在x之前就被其他数的倍数标记过，如2的倍数，3的倍数
                    for (long long j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        return ans;
    }
};
// O(nloglogn) O(n)