#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
using std::vector;
using std::unordered_map;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int> nums) {
		return _3(nums);
	}
private:
	vector<vector<int>> _1(vector<int> nums){
		//* <value, count>
		unordered_map<int, int> um;
		vector<vector<int>> v;
		for(const auto e: nums)
			um[e]++;
		for(int i = 0; i < nums.size(); ++i)
			for(int ii = i + 1; ii < nums.size(); ++ii){
				int target = -nums[i] - nums[ii];
				int count = 1;
				if(1);//TODO
			}
		return v;
	}

	/**
	 * @brief TLE, in situation like [0,0,0,0,....0]
	 */
	vector<vector<int>> _2(vector<int>& nums){
		vector<vector<int>> v;					//* store the answer
		v.push_back(vector<int>());				//* insert a "singular" vector to the front
		std::sort(nums.begin(), nums.end());
		//* unordered_map<value, index>
		std::unordered_map<int, int> um;
		for(int i = 0; i < nums.size(); ++i)
			um[nums[i]] = i;
		for(int i = 0; i < nums.size(); ++i)
			for(int ii = i + 1; ii < nums.size(); ++ii){
				int iii = um[- nums[i] - nums[ii]];
				if(iii > ii && vector<int>{nums[i], nums[ii], nums[iii]} > v.back())
					v.push_back(vector<int>{nums[i], nums[ii], nums[iii]});
			}
		v.erase(v.begin());
		return v;
	}
	/**
	 * @brief updated from _2
	 * @perf: [20, 16]
	 */
	vector<vector<int>> _3(vector<int>& nums){
		vector<vector<int>> v;					//* store the answer
		std::sort(nums.begin(), nums.end());
		//* unordered_map<value, index>
		std::unordered_map<int, int> um;
		for(int i = 0; i < nums.size(); ++i)
			um[nums[i]] = i;
		
		int sz = nums.size();
		//TODO what if all elements in nums are 0x80000000?
		nums.push_back(0x80000000);	//* to reduce edge tests
		for(int i = 0; i < sz;){
			for(int ii = i + 1; ii < sz;){
				int iii = um[- nums[i] - nums[ii]];
				if(iii > ii)
					v.push_back(vector<int>{nums[i], nums[ii], nums[iii]});
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

int main(){
	vector<int> v1 = {0, 0};
	vector<int> v2 = {-1,0,1,2,-1,-4};
	vector<int> v3 = {0, 0};
	bool b = v1 == v3;
	Solution sln;
	sln.threeSum(v2);
	return 0;
}



