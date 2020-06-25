#include <vector>
#include <algorithm>
using std::max;
using std::min;
// #include <tuple>
using std::vector;
using std::pair;


class Solution {
public:
	int maxArea(vector<int>& height) {
		return _2(height);
	}
private:
	int maxArea_1(vector<int>& height){
		//* <vector<pair<height, index>> right
		vector<pair<int, int>> right;
		//* the heightest we have meet
		int max_height = -1;
		int max_area = -1;
		for(int i = height.size() - 1; i != -1; --i){
			if(height[i] > max_height){
				right.push_back({height[i], i});
				max_height = height[i];
			}
		}
		max_height = -1;
		for(int i = 0; i < height.size(); ++i){
			if(height[i] > max_height){
				max_height = height[i];
				
			}
		}
		return 0; // make it compile
	}
	/**
	 * @perf: [30, 5]
	 * 
	 * @param height 
	 * @return int 
	 */
	int _2(vector<int>& height){
		//* pair<height, index>
		vector<pair<int, int>> v;
		v.push_back({height.back(), height.size() - 1});
		//* set up v
		for(int i = height.size() - 2; i >= 0; --i)
			if(height[i] > v.back().first)
				v.push_back({height[i], i});
		//* iterate right-ward
		int cur_max = 0;
		int ans = 0;
		for(int i = 0; i < height.size(); ++i)
			if(height[i] > cur_max){
				cur_max = height[i];
				for(int ii = 0; ii < v.size(); ++ii)
					if(v[ii].second <= i)
						break;
					else
						ans = max(ans, (v[ii].second - i) * min(height[i], v[ii].first));
			}
		return ans;
	}
};

int main(){
	vector<int> v = {1,8,6,2,5,4,8,3,7};
	Solution sln;
	sln.maxArea(v);
	return 0;
}
