/*
729. 我的日程安排表 I
需要一个数据结构能保持元素排序和支持快速插入，用TreeSet来构建。
对于给定的区间[start,end),我们每次查找七点大于等于end的第一个区间[l1,r1),
同事紧挨着[l1,r1)的前一个区间为[l2,r2),此时如果满足r2<=start<end<=l1,
则可以预定
*/

class MyCalendar {
    set<pair<int, int>> booker;
public:
    bool book(int start, int end) {
        auto it = booker.lower_bound({end, 0});
        if (it == booker.begin() || (--it)->second <= start) {
            booker.emplace(start, end);// 不用加{}
            return true;
        } else return false;
    }
};
// O(nlogn)在set内部二分查找    O(n)