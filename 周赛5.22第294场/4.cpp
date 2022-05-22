class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int res = 0;
        for (int i = 0; i < strength.size(); ++i) {
            int minn = strength[i];
            int summ = 0;
            for (int j = i; j < strength.size(); ++j) {
                minn = min(minn, strength[j]);
                summ += strength[j];
                res = (res + summ * minn) % (1000000007);
            }
        }
        return res;
    }
};
// 常规思路，做法超时，看了一个下午和一个晚上的题解都没看懂，改天再看