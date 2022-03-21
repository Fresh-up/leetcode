//使用STL的upper_bound和lower_bound函数
//auto lower_bound(nums.begin(), nums.end(), int target);
//lower_bound返回一个第一个出现元素的迭代器，如果没找到则返回end()
//upper_bound返回最后一个出现元素的下一个迭代器，如果没有返回end()
#include <algorithm>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target)-lower_bound(nums.begin(), nums.end(), target);
    }
};