#include <vector>
using std::vector;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		return _1(numRows);
	}
private:
	/**
	 * @perf: [100, 72]
	 * @time: O(n^2)
	 * @space: O(n^2)
	 */
	vector<vector<int>> _1(int numRows){
		vector<vector<int>> v(numRows);
		for(int i = 0; i < numRows; ++i){
			v[i].resize(i + 1);
			v[i].front() = 1;
			v[i].back() = 1;
			for(int ii = 1; ii < v[i].size() - 1; ++ii)
				v[i][ii] = v[i - 1][ii - 1] + v[i - 1][ii];
		}
		return v;
	}
};
