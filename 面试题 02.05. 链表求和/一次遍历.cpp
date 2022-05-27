class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* node = dummy;
        
        while (l1 || l2) {
            int tmp;
            if (l1 && l2) {
                tmp = l1->val + l2->val + c;
                l1 = l1->next;
                l2 = l2->next;
            } else if (!l1) {
                tmp = l2->val + c;
                l2 = l2->next;
            } else {
                tmp = l1->val + c;
                l1 = l1->next;
            }
            node->next = new ListNode(tmp % 10);
            c = tmp / 10;
            node = node->next;
        }
        if (c == 1) node->next = new ListNode(1);
        return dummy->next;
    }
};
// O(n+m) O(n+m)