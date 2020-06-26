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
		return _3(height);
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
	/**
	 * @brief dual pointers
	 * @perf: [6, 48]
	 */
	int _3(vector<int>& height){
		int cur_max = 0;
		int ll = 0, rr = height.size() - 1;
		while(ll < rr){
			cur_max = max(cur_max, min(height[ll], height[rr]) * (rr - ll));
			if(height[ll] < height[rr]){
				int i = ll + 1;
				while(height[i] <= height[ll])
					++i;
				ll = i;
			}else{
				int i = rr - 1;
				while(height[i] < height[rr])
					--i;
				rr = i;
			}
		}
		return cur_max;
	}
	/**
	 * @brief solution from leetcode-cn official post
	 * @perf: [15, 40]
	 * @param height 
	 * @return int 
	 */
	int _4(vector<int>& height){
		int cur_max = 0;
		int ll = 0, rr = height.size() - 1;
		while(ll < rr){
			cur_max = max(cur_max, min(height[rr], height[ll]) * (rr - ll));
			if(height[ll] < height[rr])
				++ll;
			else
				--rr;
		}
		return cur_max;
	}
};

int main(){
	vector<int> v = {1,8,6,2,5,4,8,3,7};
	Solution sln;
	sln.maxArea(v);
	return 0;
}
