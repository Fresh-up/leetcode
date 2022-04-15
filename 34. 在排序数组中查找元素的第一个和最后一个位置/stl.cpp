// STL真的好用
// upper_bound()返回第一个大于target的迭代器，没有返回end(最后一个元素的后面)
// lower_bound()返回第一个小于等于target的迭代器，没有返回end(最后一个元素的后面)
// 均采用二分查找得到的,所以时间复杂度都是logn

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (low > high) return {-1, -1};
        else return {low, high};
    }
};

// STL里面的equal_range也能达到相同效果,采用的也是二分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [l, r] = equal_range(nums.begin(), nums.end(), target);
        if (l == r) return {-1, -1};
        // 迭代器之间的减法是被允许的，
        // 两个迭代器相减返回是它们之间的距离，这个距离是一个符号类整型（signed）
        else    return {(int)(l-nums.begin()), (int)(r-nums.begin()-1)};
    }
};