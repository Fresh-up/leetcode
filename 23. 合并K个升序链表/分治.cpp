class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return m(lists, 0, lists.size() - 1);
    }
    ListNode* m(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[r];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mtwo(m(lists, l, mid), m(lists, mid + 1, r));
    }
    // 学这种分治的实现：参数：(数组，左边界，右边界)
    // mid=(l+r)>>1  从中间分，返回是合在一起的函数(参数是本函数两次调用
    // 一次是左半边，另一次是右半边)





    ListNode* mtwo(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 == nullptr ? l2 : l1;
        node = dummy->next;
        delete dummy;
        return node;
    }
};
/*
设每个链表都是n个元素(这是最坏的情况了),一共有k个链表，第一轮合并k/2组链表
每一组时间代价是O(2n);第二轮合并k/4组链表，每组时间代价是O(4n)...
总的时间代价是O(knlogk)
递归会用到O(logk)的栈空间
*/