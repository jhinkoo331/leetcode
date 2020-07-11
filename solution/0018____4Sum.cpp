#include <vector>
#include <algorithm>
#include <unordered_map>
using std::vector;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		return _1(nums, target);
	}
private:
	/**
	 * @brief 
	 * @perf: [5, 5]
	 */
	vector<vector<int>> _1(vector<int>& nums, int target){
		vector<vector<int>> v;
		if(nums.empty())
			return v;
		std::sort(nums.begin(), nums.end());
		int sz = nums.size();
		std::unordered_map<int, int> um;		//* unordered_map<value, index>
		for(int i = 0; i < nums.size(); ++i)
			um[nums[i]] = i;
		if(nums.back() < 0)				//* reduce edge tests
			nums.push_back(0);
		else
			nums.push_back(-1);
		for(int i = 0; i < sz;){
			for(int ii = i + 1; ii < sz;){
				for(int iii = ii + 1; iii < sz;){
					int iiii = um[target - nums[i] - nums[ii] - nums[iii]];
					if(iiii > iii)
						v.push_back(vector<int>{nums[i], nums[ii], nums[iii], nums[iiii]});
					while(nums[iii + 1] == nums[iii])
						++iii;
					++iii;
				}
				while(nums[ii + 1] == nums[ii])
					++ii;
				++ii;
			}
			while(nums[i + 1] == nums[i])
				++i;
			++i;
		}
		return v;
	}
};
