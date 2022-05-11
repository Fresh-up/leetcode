class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> tmp;
        while (head != nullptr) {
            tmp.emplace_back(head->val);
            head = head->next;
        }
        int l = 0, r = tmp.size() - 1;
        while (l <= r) {
            if (tmp[l++] != tmp[r--]) return false;
        }
        return true;
    }
};