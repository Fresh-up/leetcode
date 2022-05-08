class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* fast = head, *slow = head, *pre;
        while (fast != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) fast = fast->next;
        }
        pre->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        // 递归法
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val < list2->val) {
            list1->next = merge(list1->next, list2);
            return list1;
        }
        else {
            list2->next = merge(list1, list2->next);
            return list2;
        }
        return nullptr;
    }
};