#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using std::priority_queue;
using std::vector;
using std::pair;
using std::set;
using std::max;

typedef pair<int, int> loc;

	bool operator< (pair<int, loc>& lhs, pair<int, loc>& rhs){
		return lhs.first > rhs.first;
	}

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		return _2(matrix);
	}
private:
	/**
	 * @brief 
	 * * perf: [34, 30] 
	 * @param matrix 
	 * @return int 
	 */
	int _2(vector<vector<int>>& matrix){
		if(matrix.empty() || matrix.front().empty())
			return 0;
		//* v[i][ii] means, the longest sequence ends with matrix[i][ii]'s max length is v[i][ii]
		vector<vector<int>> v(matrix.size());
		for(auto& e: v)
			e.resize(matrix.front().size());

		//* sort in increasing order
		vector<pair<int, loc>> vv;
		vv.reserve(matrix.size() * matrix.front().size());
		for(int i = 0; i < matrix.size(); ++i)
			for(int ii = 0; ii <matrix.front().size(); ++ii)
				vv.push_back({matrix[i][ii], {i, ii}});
		std::sort(vv.begin(), vv.end());

		int ans = 1;
		for(int i = 0; i < vv.size(); ++i){
			loc temp = vv[i].second;
			v[temp.first][temp.second] = 1;
			if(temp.first > 0 && matrix[temp.first - 1][temp.second] < matrix[temp.first][temp.second])
				v[temp.first][temp.second] = max(v[temp.first][temp.second], v[temp.first - 1][temp.second] + 1);
			if(temp.first < matrix.size() - 1 && matrix[temp.first + 1][temp.second] < matrix[temp.first][temp.second])
				v[temp.first][temp.second] = max(v[temp.first][temp.second], v[temp.first + 1][temp.second] + 1);
			if(temp.second > 0 && matrix[temp.first][temp.second - 1] < matrix[temp.first][temp.second])
				v[temp.first][temp.second] = max(v[temp.first][temp.second], v[temp.first][temp.second - 1] + 1);
			if(temp.second < matrix.front().size() - 1 && matrix[temp.first][temp.second + 1] < matrix[temp.first][temp.second])
				v[temp.first][temp.second] = max(v[temp.first][temp.second], v[temp.first][temp.second + 1] + 1);
			//* update ans
			ans = max(ans, v[temp.first][temp.second]);
		}
		return ans;
	}
};
