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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));
        int i = 0, j = 0;
        int lt = 0, rt = n - 1, ut = 0, dt = m - 1;
        bool ltor = true, utod = false, rtol = false, dtou = false;
        while (head != nullptr) {
            if (i >= ut && i <= dt && j >= lt && j <= rt) 
                ret[i][j] = head->val;
            if (ltor) {
                if (j == rt) {
                    ltor = false;
                    ++ut;
                    utod = true;
                    ++i;
                }
                else ++j;
            } else if (utod) {
                if (i == dt) {
                    utod = false;
                    --rt;
                    rtol = true;
                    --j;
                } else ++i;
            } else if (rtol) {
                if (j == lt) {
                    rtol = false;
                    --dt;
                    dtou = true;
                    --i;
                } else --j;
            } else if (dtou) {
                if (i == ut) {
                    dtou = false;
                    ++lt;
                    ltor = true;
                    ++j;
                } else --i;
            }
            head = head->next;
        }
        return ret;
    }
};