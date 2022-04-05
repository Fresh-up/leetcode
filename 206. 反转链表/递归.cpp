struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归
        if (!head || !head->next) return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;

    }
};
//O(n) O(n)其中 nn 是链表的长度。
//空间复杂度主要取决于递归调用的栈空间，最多为 nn 层。