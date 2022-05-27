class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* node = nullptr;
        for (const auto& list : lists) {
            node = mtwo(node, list);
        }
        return node;
    }
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
            node = node->next;// 忘了这茬
        }
        node->next = l1 == nullptr ? l2 : l1;
        node = dummy->next;
        delete dummy;
        return node;
    }
};
// 设每个链表长度都是n，一共有k个链表，则O(k^2*n)
// 空间复杂度O(1)