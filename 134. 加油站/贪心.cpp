#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {//从第i个开始出发
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;//一开始是第0个
            while (cnt < n) {
                int j = (i + cnt) % n;//数组走环
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) 
                    break;
                cnt++;
            }
            if (cnt == n) {//走完环
                return i;
            } else {
                i = i + cnt + 1;//如果从x开始走，走不到y
                //那么从x到y-1任一点出发也到不了y
            }
        }
        return -1;
    }
};