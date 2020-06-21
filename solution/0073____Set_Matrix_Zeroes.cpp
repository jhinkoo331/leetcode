#include <vector>
using std::vector;

//TODO: in-place, quite easy, use space in the matrix to store data in `row` and `col` in _1
//TODO: solution and discuss


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		_1(matrix);
	}
private:
	/**
	 * @perf: [75, 49]
	 * @time: O(mn), size of the matrix
	 * @space: O(m + n)
	 * @param matrix 
	 */
	void _1(vector<vector<int>>& matrix){
		if(matrix.empty())	//* anchor
			return;
		vector<int> col(matrix.front().size(), 0);		//ANCHOR
		vector<int> row(matrix.size(), 0);
		for(int i = 0; i < matrix.size(); ++i)
			for(int ii = 0; ii < matrix[i].size(); ++ii)
				if(matrix[i][ii] == 0){
					row[i] = 1;
					col[ii] = 1;
				}
		//* set column zero
		for(int i = 0; i < col.size(); ++i)
			if(col[i])
				for(int ii = 0; ii < matrix.size(); ++ii)
					matrix[ii][i] = 0;
		//* set row zero
		for(int i = 0; i < row.size(); ++i)
			if(row[i])
				for(int ii = 0; ii < matrix[i].size(); ++ii)
					matrix[i][ii] = 0;
		return;
	}
};
