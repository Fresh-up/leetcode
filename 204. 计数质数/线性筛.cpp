// 埃氏筛还是存在冗余标记，如45,它会被3,5两个数标记为合数
// 标记过程与埃氏筛不同，不再仅当x为质数时才进行，而是对每个整数x都进行
// 保证是每个合数被它较小的那个质数所标记，所以i % primes[j] == 0就跳出
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;// 存放质数
        vector<bool> isPrime(n, true);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) primes.emplace_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) break;
            }
        }
        return primes.size();
    }
};
// O(n) O(n)