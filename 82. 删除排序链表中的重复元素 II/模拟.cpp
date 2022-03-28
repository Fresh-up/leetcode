struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//思路：找规律
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);//学会构造新节点
        dummy->next = head;
        ListNode* node = dummy;
        int num = -101;//题目给的节点val范围是-100~100
        while (head){
            if (head->val == num){
                //如果node->next是重复元素，先置空,抬起枪口
                node->next = nullptr;
                head = head->next;
            }
            else {
                if (!head->next || head->next->val != head->val){
                    node->next = head;
                    num = head->val;
                    node = head;
                }
                else {
                    num = head->val;
                }
                head = head->next;
            }
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};
//O(n) O(3)