#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		return _1(board, word);
	}
private:
	/**
	 * @brief 
	 * @perf: [98, 77]
	 * @param board 
	 * @param word 
	 * @return true 
	 * @return false 
	 */
	bool _1(vector<vector<char>>& board, string word){
		if(board.empty() || board[0].empty())
			return word.empty();
		if(word.empty())
			return true;
		//* wrap the matrix with a circle of '-' to reduce edge tests
		board.insert(board.begin(), vector<char>(board[0].size() + 2, '-'));
		board.push_back(vector<char>(board[0].size() + 2, '-'));
		for(int i = 0; i < board.size() - 1; ++i){
			board[i].insert(board[i].begin(), '-');
			board[i].push_back('-');
		}
		for(int i = 1; i < board.size() - 1; ++i)
			for(int ii = 1; ii < board[i].size() - 1; ++ii)
				if(board[i][ii] == word[0] && _1_dfs(board, i, ii, word, 1))
					return true;
		return false;
	}
	bool _1_dfs(vector<vector<char>>& board, int row, int col, const string& word, int index){
		if(index == word.size())
			return true;
		board[row][col] |= 0x80;
		if(!(board[row - 1][col] & 0x80) && board[row - 1][col] == word[index] && _1_dfs(board, row - 1, col, word, index + 1))
			return true;
		if(!(board[row + 1][col] & 0x80) && board[row + 1][col] == word[index] && _1_dfs(board, row + 1, col, word, index + 1))
			return true;
		if(!(board[row][col - 1] & 0x80) && board[row][col - 1] == word[index] && _1_dfs(board, row, col - 1, word, index + 1))
			return true;
		if(!(board[row][col + 1] & 0x80) && board[row][col + 1] == word[index] && _1_dfs(board, row, col + 1, word, index + 1))
			return true;
		board[row][col] &= 0x7f;
		return false;
	}
};


int main(){
	vector<vector<char>> board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	vector<vector<char>> b = {{'A', 'A'}};
	Solution sln;
	sln.exist(b, "AAA");
	return 0;
}