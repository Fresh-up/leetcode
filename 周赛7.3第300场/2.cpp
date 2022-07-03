// 自己的办法，面向过程编程i🤣
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

// 别人的办法，稍作修改
class Solution {
    // 四个方向，按右、下、左、上顺序记录（因为螺旋也是按这个顺序转的）
    short dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        // (i, j) 是当前矩阵中的坐标，D 是当前的方向
        int i = 0, j = 0, D = 0;
        while (head) {
            // 填写当前位置
            ans[i][j] = head->val;
            head = head->next;
            // 算出下一个位置的坐标, 试着往当前方向走一步
            int ii = i + dir[D][0], jj = j + dir[D][1];
            // 会走出矩阵或走到已有数字的格子中，换一个方向
            if (ii < 0 || jj < 0 || ii >= m || jj >= n || ans[ii][jj] >= 0) D = (D + 1) % 4;
            // ans[ii][jj] >= 0这个判断很关键
            i += dir[D][0], j += dir[D][1];
        }
        return ans;
    }
};