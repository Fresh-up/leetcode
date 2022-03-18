/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//看到这题我首先想到的是反转链表，而不是求长度，我之前做过的题目对我产生了影响
// 在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），
// 它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。
class Solution {
public:
    int getlen(ListNode* head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
// 特别地，在某些语言中，由于需要自行对内存进行管理。因此在实际的面试中，
// 对于「是否需要释放被删除节点对应的空间」这一问题，
// 我们需要和面试官进行积极的沟通以达成一致。下面的代码中默认不释放空间。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getlen(head);
        n = len - n + 1;
        ListNode* dummy = new ListNode(0, head);
        ListNode* node = dummy;
        while(n != 1){
            node = node->next;
            --n;
        }
        node->next = node->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
//0ms 100%
//10.4MB 51.15%