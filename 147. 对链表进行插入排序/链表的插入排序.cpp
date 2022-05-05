// 链表左边是排序好的节点，右边是没有排序好的节点，sorted记录排序好
// 的最后一个节点，curr是sorted下一个节点，如果大于sorted,则sorted向后移
// 如果小于，则从头遍历到sorted找到curr应该在的位置。
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = head->next;
        ListNode* sorted = head;
        while (curr != nullptr){
            if (curr->val >= sorted->val){
                sorted = sorted->next;
            }
            else {
                ListNode* prev = dummy;
                while (prev->next->val < curr->val){
                    prev = prev->next;
                }
                sorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = sorted->next;
        }
        return dummy->next;
    }
};
// O(n^2) O(1)