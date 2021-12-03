#include <vector>
#include <algorithm>
using std::vector;

bool cmp(const vector<int>& lhs, const vector<int>& rhs){
	if(lhs[0] != rhs[0])
		return lhs[0] < rhs[0];
	else
		return lhs[1] < rhs[1];
}


class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		return _1(intervals);
	}
private:
	int ans;
	int _1(vector<vector<int>>& intervals){
		ans = 0;
		if(intervals.empty())
			return ans;
		std::sort(intervals.begin(), intervals.end());
		_1_remove_full_overlapped(intervals);
		_1_remove_half_overlapped(intervals);
		return ans;
	}
	void _1_remove_full_overlapped(vector<vector<int>>& intervals){
		int temp = 0;
		for(size_t i = 1; i < intervals.size(); ++i)
			if(intervals[temp][0] < intervals[i][0] && intervals[temp][1] < intervals[i][1])
				intervals[++temp] = intervals[i];
		ans += intervals.size() - (temp + 1);
		intervals.resize(temp + 1);
	}
	void _1_remove_half_overlapped(vector<vector<int>>& intervals){
		int right_edge = 0x80000000;
		for(int i = 0; i < intervals.size(); ++i)
			if(right_edge <= intervals[i][0])
				right_edge = intervals[i][1];
			else
				++ans;
	}
};

int main(){
	vector<vector<int>> v = {{1,2}};
	vector<vector<int>> v2 = {{1,2}, {2,3}, {3,4}, {1,3}};
	Solution sln;
	sln.eraseOverlapIntervals(v2);
	return 0;
}