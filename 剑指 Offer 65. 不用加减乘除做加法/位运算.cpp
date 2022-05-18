class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {// 当进位为0时跳出
            // 要加unsigned int否则会溢出
            int c = (unsigned int)(a & b) << 1;// c = 进位
            a ^= b;// a = 非进位和
            b = c;// b = 进位
        }
        return a;
    }
};
// O(1) O(1)