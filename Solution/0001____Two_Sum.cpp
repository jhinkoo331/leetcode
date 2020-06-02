#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target){
		return twoSum_2(nums, target);
	}
private:
	// pair<value, index>
	vector<vector<pair<int, int>>> data;
	vector<int> twoSum_1(vector<int>& nums, int target) {
		data.resize(0x00010000);
		int sz = nums.size();
		for(int i = 0; i != sz; ++i){
			data[nums[i] & 0x0000ffff].push_back(make_pair(nums[i], i));
		}
		for(int i = 0; i != sz; ++i){
			int couple = target - nums[i];				// nums[i] + couple == target
			int couple_col = couple & 0x0000ffff;		// `couple` is stored in data[couple_col]
			for(const auto& elem: data[couple_col]){
				if(elem.first == couple && i != elem.second)		// solution found
					return vector<int> {i, elem.second};
			}
		}
		return vector<int> {};		// 'cuz there is always solution, this line is never reached, add this line to make compile pass.
	}
	//* [87, 57]
	vector<int> twoSum_2(vector<int>& nums, int target){
		data.resize(16);
		int sz = nums.size();
		for(int i = 0; i != sz; ++i)
			data[nums[i] & 0xf].push_back(make_pair(nums[i], i));
		for(int i = 0; i != sz; ++i){
			int couple = target - nums[i];
			int couple_col = couple & 0xf;
			int sz_2 = data[couple_col].size();
			for(int ii = 0; ii != sz_2; ++ii){
				if(data[couple_col][ii].first == couple && i != data[couple_col][ii].second)
					return vector<int> {i, data[couple_col][ii].second};
			}
		}
		return vector<int> {};
	}
	//* [87, 87]
	vector<int> twoSum_3(vector<int>& nums, int target){
		unordered_map<int, int> mp;
		for(int i = 0; i < nums.size(); ++i){
			int temp = target - nums[i];
			if(mp.count(temp)){
				return {i, mp[temp]};
			}else{
				mp[nums[i]] = i;
			}
		}
		return {};
	}
};
