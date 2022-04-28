/* 思路：一次遍历把元素推入哈希集合，再次遍历数组，如果当前元素
的值的前一个元素不在集合中，说明此元素可以作为起始元素，然后在
哈希集合中遍历找到最长序列，记录；如果值的前一个元素在集合中，说明
此元素不是起始元素，可以跳过。每次访问哈希集合复杂度为O(1)
不但访问快，而且还可以去重
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset;
        for (const auto& num : nums) myset.insert(num);

        int longest = 0;
        for (const auto& num : nums){
            int tmp = 1;
            int n = num;
            if (myset.count(n - 1)) continue;
            else {
                while (myset.count(n + 1)){
                    ++tmp;
                    ++n;
                }
                longest = max(longest, tmp);
            }
        }
        return longest;
    }
};
// O(n) O(n)

/* 真是见鬼了，明明跟官方解法差不多一样，就是变量名换了一下，
但是速度差了10倍
*/
