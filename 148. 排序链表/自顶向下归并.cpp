class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail){
        if (head == nullptr){
            return head;
        }
        if (head->next == tail){
            head->next = nullptr;
            return head;
        }
        // 快慢指针找中点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != tail){
            fast = fast->next;
            slow = slow->next;
            if (fast != tail) fast = fast->next;
        }

        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        node->next = list1 == nullptr ? list2 : list1;
        return dummy->next;
    }
};
// O(nlogn)  O(logn)主要取决于递归的栈空间