// 我们可以枚举字符串中的每一个位置作为右端点，
// 然后找到其最远的左端点的位置，满足该区间内除了出现
// 次数最多的那一类字符之外，剩余的字符（即非最长重复字符）数量
// 不超过 k 个。
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxn = 0;
        vector<int> freq(26, 0);

        while (r < n){
            ++freq[s[r] - 'A'];
            maxn = max(maxn, freq[s[r] - 'A']);
            // maxn记录重复字符出现次数的历史最大值
            if (r - l + 1 - maxn > k){
                --freq[s[l] - 'A'];
                ++l;
            }
            ++r;
        }
        return r - l;
    }
};
// O(n) O(n)