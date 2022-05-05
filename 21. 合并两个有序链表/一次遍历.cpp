class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        // dummy->next = list1 == nullptr? list2 : list1;
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
        node->next = list1 == nullptr? list2 : list1;
        return dummy->next;
    }
};