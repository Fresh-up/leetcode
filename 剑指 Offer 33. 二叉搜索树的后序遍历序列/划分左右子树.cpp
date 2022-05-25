/* 后序遍历[左子树 | 右子树 | 根节点]
划分左右子树：遍历[i,j]内的元素，寻找第一个大于根节点的节点，索引记为m，
可划分出左子树区间[i, m-1]，右子树[m, j-1]，根节点[j]
左子树区间[i, m-1]内所有节点都应该 < postorder[j] 而划分左右子树时已经
保证左子树区间的正确性，因此只需判断右子树区间
右子树区间[m, j-1]所有节点都应该 > postorder[j] 遍历，当遇到 <= postorder[j]
的节点则跳出，可通过 p == j判断是否为二叉搜索树
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return judge(postorder, 0, postorder.size() - 1);
    }
    bool judge(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int p = l, m = 0;
        while (p <= r && postorder[p] < postorder[r]) ++p;
        m = p;
        while (p <= r && postorder[p] > postorder[r]) ++p;
        if (p != r) return false;
        else return judge(postorder, m, r - 1) && judge(postorder, l, m - 1);
        // 不光是要判断右子树，左子树也要判断
    }
};
// O(n^2) O(n)