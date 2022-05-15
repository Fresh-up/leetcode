class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        for (int i = 0; i <= 30; ++i) {
            if (x >> i & 1) ++y;
        }
        return y;
    }
};
// O(logC), C是元素的数据范围，本题中logC = log 2^31 = 31
// O(1)