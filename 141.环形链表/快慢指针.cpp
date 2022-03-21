class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                //注意判断fast为空的先后顺序
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
//时间复杂度是O(N),空间复杂度是O(1)