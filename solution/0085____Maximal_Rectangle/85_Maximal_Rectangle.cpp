#include <vector>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(matrix.empty()){
			return 0;
		}
		int row = matrix.size(), col = matrix.front().size();
		//* check whether there is at least a `1` in the matrix
		bool has_one = 0;
		for(int i = 0; i < matrix.size(); ++i){
			for(int ii = 0; ii < matrix.front().size(); ++ii){
				if(matrix[i][ii] == 1){
					has_one = true;
					break;
				}
			}
			if(has_one){
				break;
			}
		}
		int rec_row = 1, rec_col = 1;
		if(has_one == 0){		//* no `1` in the original matrix
			return 0;
		}
		while(row > 0){
			//* try to expand vertically
			for(int i = 0; i < row; i++){
				for(int ii = 0; ii < col - 1; ++ii){
					if(matrix[i][ii] && matrix[i][ii + 1]){
						matrix[i][ii] = 1;
					}else{
						matrix[i][ii] = 0;
					}
				}
			}
		}
	}
};

