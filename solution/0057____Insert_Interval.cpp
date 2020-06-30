#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		return _1(intervals, newInterval);
	}
private:
	/**
	 * @brief 
	 * @perf: [31, 30]
	 * @return vector<vector<int>> 
	 */
	//TODO binary search
	vector<vector<int>> _1(vector<vector<int>>& intervals, vector<int>& newInterval){
		int ll, rr;
		int cur = 0;
		//* the fist interval connects with newInterval or at right side of it
		for(; cur < intervals.size(); ++cur)
			if(intervals[cur][1] >= newInterval[0])
				break;
		ll = cur;
		//* the first interval that at left size of the new interval
		for(; cur < intervals.size(); ++cur)
			if(newInterval[1] < intervals[cur][0])
				break;
		rr = cur;
		
		if(ll == rr){		//* insert
			intervals.insert(intervals.begin() + ll, newInterval);
		}else{			//* merge and remove
			newInterval[0] = min(newInterval[0], intervals[ll][0]);
			newInterval[1] = max(newInterval[1], intervals[rr - 1][1]);
			intervals[ll] = newInterval;
			intervals.erase(intervals.begin() + ll + 1, intervals.begin() + rr);
		}
		return intervals;
	}
};

int main(){
	Solution sln;
	vector<vector<int>> v = {{1,3},{6,9}};
	vector<int> vv = {2,5};
	sln.insert(v, vv);
	return 0;
}