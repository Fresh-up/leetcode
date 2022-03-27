struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//思路：找规律，注意k可能大于节点个数，需要取余，同时注意k=0的情况
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* dummy = head;
        int num = 1;
        while (head->next){
            ++num;
            head = head->next;
        }
        if (k != 0){
            head->next = dummy;
        }
        k = k % num;
        num = num - k;
        while (num){
            head = head->next;
            --num;
        }
        ListNode* node = head->next;
        head->next = nullptr;
        return node;
    }
};
//O(2n-k)
//O(2)