//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//具体我解题过程：
//先把特殊条件写出，然后再写两个节点的，然后再写n个节点的。
//用时大概5min
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
        return tmp;
    }
};
//O(n) O(n)做链表的题目越来越得心应手了