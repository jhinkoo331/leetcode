#include "util\frequently_included.h"

inline int get_sub_index(int row, int col){
        return (row / 3) * 3 + col / 3;
}

class Solution {
public:
        void solveSudoku(vector<vector<char>>& board) {
                _1(board);
        }
private:
        void _1(vector<vector<char>>& board){
                vector<int> sub(9, 0);
                for(int i = 0; i < 9; ++i)
                        for(int ii = 0; ii < 9; ++ii)
                                if(board[i][ii] != '.'){
                                        char temp = board[i][ii] - '0';
                                        sub[get_sub_index(i, ii)] |= 1 << temp;
                                }
                _1_dfs(board, sub, 0, 0);
        }
        bool _1_dfs(vector<vector<char>>& board, vector<int>& sub, int i, int ii){
                if(ii == 9){
                        i++;
                        ii = 0;
                }
                if(i == 9)
                        return true;
                if(board[i][ii] == '.'){
                        for(int mask = 1; mask <= 9; ++mask){
                                int temp = 1 << mask;
                                if(!(temp & row[i]) && !(temp & col[i]) && !(temp & sub[get_sub_index(i, ii)])){
                                        row[i] |= temp;
                                        col[ii] |= temp;
                                        sub[get_sub_index(i, ii)] |= temp;
                                        board[i][ii] = '0' + mask;
                                        if(_1_dfs(board, row, col, sub, i, ii + 1))
                                                return true;
                                        row[i] ^= temp;
                                        col[ii] ^= temp;
                                        sub[get_sub_index(i, ii)] ^= temp;
                                        board[i][ii] = '.';
                                }
                        }
                        return false;
                }else{
                        return _1_dfs(board, row, col, sub, i, ii + 1);
                }
        }
};

int main(){
        vector<vector<char>> board = {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };
        Solution sln;
        sln.solveSudoku(board);
        return 0;
}

