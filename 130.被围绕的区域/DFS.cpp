#include <vector>
using namespace std;

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();


        for (int i = 0; i < m; ++i){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'F') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() || (board[i][j] == 'X') || (board[i][j] == 'F')) return;

        //现在这个点是'O'
        board[i][j] = 'F';
        int x, y;
        for (int k = 0; k < 4; ++k){
            x = i + direction[k], y = j + direction[k+1];
            dfs(board, x, y);
        }
        //dfs(board, i+1, j);
        //dfs(board, i, j+1);
        //dfs(board, i-1, j);
        //dfs(board, i, j-1);
        //可能这好点，节省一点点空间
    }
};
//O(n×m)深度优先搜索过程中，每一个点至多只会被标记一次
//O(n×m)主要为深度优先搜索的栈的开销