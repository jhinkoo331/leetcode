#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
		if(matrix.empty()){
			return 0;
		}
        int count = 0;
		int row = matrix.size();
		int col = matrix.front().size();		//* matrix is not empty here
		while(row != 0 && col != 0){
			for(int i = 0; i < row; ++i){
				for(int ii = 0; ii < col; ++ii){
					if(matrix[i][ii] != 0){
						count++;
					}
				}
			}
			for(int i = 0; i < row - 1; ++i){
				for(int ii = 0; ii < col - 1; ++ii){
					if(matrix[i][ii] != 0 && matrix[i][ii + 1] != 0 && matrix[i + 1][ii] != 0 && matrix[i + 1][ii + 1] != 0){
						matrix[i][ii] = 1;
					}else{
						matrix[i][ii] = 0;
					}
				}
			}
			row--;
			col--;
		}
		return count;
    }
};


int main(){
	vector<vector<int>> matrix1 = {
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 1, 1, 1}
	};
	vector<vector<int>> matrix2 = {
		{1, 0, 1},
		{1, 1, 0},
		{1, 1, 0}
	};
	Solution sln;
	sln.countSquares(matrix1);
	sln.countSquares(matrix2);
	return 0;
}