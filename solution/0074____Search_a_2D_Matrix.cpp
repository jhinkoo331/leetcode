#include <vector>
using std::vector;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		return _1(matrix, target);
	}
private:
	/**
	 * @brief 
	 * @perf: [79, 83]
	 * @param matrix 
	 * @param target 
	 * @return true 
	 * @return false 
	 */
	bool _1(vector<vector<int>>& matrix, int target){
		//* empty test
		if(matrix.empty() || matrix[0].empty())
			return false;
		//* binary search in rows
		int r = 0, rr = matrix.size() - 1;
		while(r + 1 < rr){
			int mid = (rr - r) / 2 + r;
			if(matrix[mid][0] <= target)
				r = mid;
			else
				rr = mid - 1;
		}
		if(matrix[rr][0] <= target)
			r = rr;
		//* binary search in matrix[r]
		int c = 0, cc = matrix[0].size() - 1;
		while(c <= cc){
			int m = (cc - c) + c;
			if(matrix[r][m] == target)
				return true;
			else if(matrix[r][m] < target)
				c = m + 1;
			else
				cc = m - 1;
		}
		//*
		return false;
	}
};
