//不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句，只有加减法、赋值、位运算符以及逻辑运算符可用
// 利用&&的短路性质，a && b一旦a为false,便不会执行b，即可跳出递归
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
// O(n) O(n)