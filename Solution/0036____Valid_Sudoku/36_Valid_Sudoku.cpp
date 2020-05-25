#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> v(10);
		//* check every row
		for(int i = 0; i < 9; ++i){			//* row
			fill(v.begin(), v.end(), 0);
			for(int ii = 0; ii < 9; ++ii){		//* column
				if(board[i][ii] == '.')
					continue;
				int num = board[i][ii] - '0';
				if(v[num] == 1){
					return false;
				}else{
					v[num] = 1;
				}
			}
		}
		//* check every column
		for(int i = 0; i < 9; ++i){			//* column
			fill(v.begin(), v.end(), 0);
			for(int ii = 0; ii < 9; ++ii){		//* row
				if(board[ii][i] == '.')
					continue;
				int num = board[ii][i] - '0';
				if(v[num] == 1){
					return false;
				}else{
					v[num]= 1;
				}
			}
		}
		//* check every sub-matrix
		for(const auto& elem: this->vp){			//* sub-matrix
			fill(v.begin(), v.end(), 0);
			for(int i = 0; i < 3; ++i){			//* row
				for(int ii = 0; ii < 3; ++ii){		//* column
					if(board[elem.first + i][elem.second + ii] == '.')
						continue;
					int num = board[elem.first + i][elem.second + ii] - '0';
					if(v[num] == 1){
						return false;
					}else{
						v[num] = 1;
					}
				}
			}
		}
		return true;
	}
private:
	const vector<pair<int, int>> vp = {
		{0, 0}, {0, 3}, {0, 6},
		{3, 0}, {3, 3}, {3, 6},
		{6, 0}, {6, 3}, {6, 6}
	};
};

int main(){
	vector<vector<char>> v = {
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
	sln.isValidSudoku(v);
	return 0;
}