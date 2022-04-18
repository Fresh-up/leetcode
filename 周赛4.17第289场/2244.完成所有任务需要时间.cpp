// 自己写的
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // if (tasks.size() == 1) return -1;
        int minr = 0;
        sort(tasks.begin(), tasks.end());
        int pre = tasks[0];
        int num = 0;
        for (const auto& i : tasks){
            if (i == pre){
                ++num;
            }
            else {
                pre = i;
                int ge = num / 3;
                int yu = num % 3;
                if (yu == 2){
                    minr = minr + ge + 1;
                } 
                else if (yu == 0){
                    minr += ge;
                }
                else {
                    if (ge == 0)
                        return -1;
                    else minr = minr + ge + 1;
                }
                num = 1;
            }
        }
        int ge = num / 3;
        int yu = num % 3;
        if (yu == 2){
            minr = minr + ge + 1;
        } 
        else if (yu == 0){
            minr += ge;
        }
        else {
            if (ge == 0)
                return -1;
            else minr = minr + ge + 1;
        }
        return minr;
    }
};

// 别人写的
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mymap;
        int ans = 0;
        for (const auto& i : tasks){
            ++mymap[i];
        }
        for (const auto& i : mymap){
            int t = i->second;
            if (t == 1) return -1;
            else if (t == 2) ++ans;
            else if (t % 3 == 0) ans += t / 3;
            else ans += t / 3 + 1;
        }
        return ans;
    }
};
/* 总结：
1. 别老想着一次遍历就行，多用数据结构
2. map区别于unordered_map，优点在于便于遍历
*/