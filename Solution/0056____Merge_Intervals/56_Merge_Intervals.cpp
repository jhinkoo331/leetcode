#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class cmp{
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) const {
		if(lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		else
			return lhs[1] < rhs[1];
	}
};

bool Cmp(const vector<int>& lhs, const vector<int>& rhs){
	if(lhs[0] != rhs[0])
		return lhs[0] < rhs[0];
	else
		return lhs[1] < rhs[1];
}

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<int> valid(intervals.size(), 1);
		sort(intervals.begin(), intervals.end(), Cmp);
		for(int i = 0; i < intervals.size(); ++i){
			if(valid[i]){		//* try to merge
				for(int ii = i + 1; ii < intervals.size(); ++ii){
					if(intervals[ii][0] <= intervals[i][1]){
						intervals[i][1] = max(intervals[ii][1], intervals[i][1]);
						valid[ii] = 0;
					}else{
						break;
					}
				}
			}else{
				continue;
			}
		}
		vector<vector<int>> ret;
		for(int i = 0; i < intervals.size(); ++i){
			if(valid[i]){
				ret.push_back(intervals[i]);
			}
		}
		return ret;
	}
};

int main(){
	vector<vector<int>> v1 = {
		{1, 3},
		{2, 6},
		{8, 10},
		{15, 18}
	};
	vector<vector<int>> v2 = {
		{1, 4},
		{4, 5}
	};
	vector<vector<int>> v3 = {};
	Solution sln;
	sln.merge(v1);
	sln.merge(v2);
	sln.merge(v3);
	return 0;
}