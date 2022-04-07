#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    //ector<int> direction{-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        //int len = word.size(), index = 0;
        if (board.empty()) return false;
        bool found = false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n, false));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                //backtrack(board, word, visited, i, j, len, index);
                backtrack(board, word, found, visited, i, j, 0);
            }
        }
        //return index == (len - 1);
        return found;
    }
    void backtrack(vector<vector<char>>& board, string word, bool &found, vector<vector<bool>>& visited, int i, int j, int pos){
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size()) return;
        
        if (visited[i][j] || found || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1){
            found = true;
            return;
        }

        visited[i][j] = true;
        backtrack(board, word, found, visited, i+1, j, pos+1);//要记住pos+1
        backtrack(board, word, found, visited, i-1, j, pos+1);
        backtrack(board, word, found, visited, i, j+1, pos+1);
        backtrack(board, word, found, visited, i, j-1, pos+1);
        visited[i][j] = false;
    }
};