#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using std::sort;
using std::vector;
using std::priority_queue;
using std::pair;


//* this function is crucial when erasing "full overlapped" intervals
bool operator< (const vector<int>& lhs, const vector<int>& rhs){
	if(lhs.front() != rhs.front())
		return lhs.front() < rhs.front();
	else
		return lhs.back() > rhs.back();
}

bool operator< (const pair<int, int> lhs, const pair<int, int> rhs){
	return lhs.first < rhs.second;
}

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		return eraseOverlapIntervals_1(intervals);
	}
private:
	int eraseOverlapIntervals_1(vector<vector<int>>& intervals){
		vector<int> valid(intervals.size(), 1);
		//* pair<interval's right value, index in `intervals`>
		priority_queue<pair<int, int>> pq;
		pq.push({0x10000000, -1});		//* make pq never empty
		sort(intervals.begin(), intervals.end());
		for(int i = 0; i < intervals.size(); ++i){
			while(pq.top().first >= intervals[i][1]){
				valid[pq.top().second] = 0;
				pq.pop();
			}
			pq.push({intervals[i][1], i});
		}
		int count = 0;
		int last_right = 0x10000000;
		for(int i = 0; i < intervals.size(); ++i){
			if(valid[i]){
				if(intervals[i][0] >= last_right){
					count++;
					last_right = intervals[i][1];
				}
			}
		}
		return count;
	}
};
