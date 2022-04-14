/* 做了一天的题，也就做了3 4道，本想着选道简单的来找回点秒杀的快感
这道题逻辑简单，但是实现起来真不简单，总结：
1. string的初始化("0")
2. string的从头部插入str.insert(0, n, "0") 和str.insert(0, "0")插入的是string 非char
3. string的反转, reverse(str.begin(), str.end()); 
*/
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        bool flag = false;
        int lenmat = a.size() - b.size();
        string res("0");// 记得这样初始化string
        if (lenmat > 0)
            b.insert(0, lenmat, '0');// 三个参数的insert()里面的是双引号
        else a.insert(0, -lenmat, '0');
        int p = a.size() - 1;
        // [1111][0001]->[1100]
        // [00]
        while(p >= 0){
            if (flag){// 有进位
                if (a[p] == '1' && b[p] == '1'){
                    res.insert(0, "1");
                }else if ((a[p] == '0' && b[p] == '1') || 
                    (a[p] == '1' && b[p] == '0')){
                    res.insert(0, "0");
                    //flag = true;这里写错了逻辑
                }else {
                    res.insert(0, "1");
                    flag = false;
                }
            }
            else {// 无进位
                if (a[p] == '1' && b[p] == '1'){
                    res.insert(0, "0");// 两个参数的insert()里面的是双引号
                    flag = true;
                }else if ((a[p] == '0' && b[p] == '1') || 
                    (a[p] == '1' && b[p] == '0')){
                    res.insert(0, "1");
                }else {
                    res.insert(0, "0");
                }
            }
            --p;
        }
        if (flag) res.insert(0, "1");
        res.pop_back();
        return res;
    }
};
// O(n) O(1)