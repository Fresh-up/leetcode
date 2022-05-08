class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int n = 0;
        ListNode* p = head;
        while (head) {
            ++n;
            head = head->next;
        }
        return sortList(p, n);
    }
    ListNode* sortList(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) return head;

        int mid = n / 2;
        ListNode* l = head, *r = head, *p;
        for (int i = 1; i < mid; ++i, r = r->next);
        p = r->next;
        r->next = nullptr;
        r = p;

        l = sortList(l, mid);
        r = sortList(r, mid);

        ListNode* dummy = new ListNode(0, nullptr);
        p = dummy;
        while (l || r) {
            if (r == nullptr || (l && l->val <= r->val)) {
                p->next = l;
                l = l->next;
                p = p->next;
            }
            else {
                p->next = r;
                r = r->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};