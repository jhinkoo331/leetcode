#include <vector>
using namespace std;


class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix){
		if(matrix.empty()){
			return 0;
		}
		//* search for square
		int row = matrix.size(), col = matrix.front().size();
		int len = 0;
		for(int i = 0; i < matrix.size() - len; ++i){
			for(int ii = 0; ii < matrix.front().size(); ++ii){
				if(matrix[i][ii] == '1'){
					while(this->is_square(matrix, i, ii, len + 1)){
						len++;
					}
				}
			}
		}
		return len * len;
	}
private:
	bool is_square(const vector<vector<char>>& matrix, int i, int ii, int len){
		int j = i + len - 1;
		int jj = ii + len - 1;
		if(j >= matrix.size() || jj >= matrix.front().size()){
			return false;
		}
		for(int k = i; k <= j; ++k){
			for(int kk = ii; kk <= jj; ++kk){
				if(matrix[k][kk] == '0'){
					return false;
				}
			}
		}
		return true;
	}
};


int main(){
	vector<vector<char>> v1 = {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};
	vector<vector<char>> v2 = {};
	Solution sln;
	sln.maximalSquare(v1);
	sln.maximalSquare(v2);
	return 0;
}