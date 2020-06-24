#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;
using std::pair;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		return _1(heights);
	}
private:
	/**
	 * @perf: [90, 14]
	 * 
	 * @param heights 
	 * @return int 
	 */
	int _1(vector<int> heights){
		//* decreasing stack 
		vector<pair<int, int>> v;
		int cur_max = 0;
		for(int i = 0; i < heights.size(); ++i){
			//* update max
			if(i + 1 < heights.size() && heights[i] <= heights[i + 1]){
				//* pass
			}else{
				cur_max = max(cur_max, heights[i]);
				for(int ii = 0; ii < v.size(); ++ii){
					cur_max = max(cur_max, min(v[ii].first, heights[i]) * (i - v[ii].second + 1));
					if(v[ii].first >= heights[i])
						break;
				}
			}
			//* update v
			v.push_back({heights[i], i});
			while(v.size() >= 2 && v[v.size() - 1].first <= v[v.size() - 2].first){
				v[v.size() - 2].first = v[v.size() - 1].first;
				v.pop_back();
			}
		}
		return cur_max;
	}
};
