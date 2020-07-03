#include <vector>
using std::vector;


class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		_1_init(matrix);
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return _1_query(row1, col1, row2, col2);
	}
private:
	vector<vector<int>>* v;
	/**
	 * @brief 
	 * @perf: [93, 99]
	 * @param matrix 
	 */
	void _1_init(vector<vector<int>>& matrix){
		if(matrix.empty() || matrix.front().empty()){
			v = &matrix;
			return;
		}
		for(int i = 1; i < matrix[0].size(); ++i)
			matrix[0][i] += matrix[0][i - 1];
		for(int i = 1; i < matrix.size(); ++i){
			for(int ii = 1; ii < matrix.front().size(); ++ii)
				matrix[i][ii] += matrix[i][ii - 1];
			for(int ii = 0; ii < matrix[0].size(); ++ii)
				matrix[i][ii] += matrix[i - 1][ii];
		}
		this->v = &matrix;
	}
	/**
	 * @brief we assume that [rr, cc] is always valid
	 * 
	 * @param r 
	 * @param c 
	 * @param rr 
	 * @param cc 
	 * @return int 
	 */
	int _1_query(int r, int c, int rr, int cc){
		--r;
		--c;
		int ans = (*v)[rr][cc];
		if(r != -1 && c != -1)
			ans += (*v)[r][c];
		if(r != -1)
			ans -= (*v)[r][cc];
		if(c != -1)
			ans -= (*v)[rr][c];
		return ans;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
	vector<vector<int>> v = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};
	NumMatrix nm(v);
	return 0;
}