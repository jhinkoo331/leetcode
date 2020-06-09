#include <vector>
#include <algorithm>
#include <set>
using std::vector;

//TODO: https://leetcode.com/problems/contains-duplicate/discuss/60937/3ms-Java-Solution-with-Bit-Manipulation

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		return containsDuplicate_2(nums);
	}
private:
	/*
	 * perf: [32, 64]
	 * time: O(nlog(n))
	 * space: O(1)
	 */
	bool containsDuplicate_1(vector<int>& nums){
		std::sort(nums.begin(), nums.end());
		for(int i = 1; i < nums.size(); ++i)
			if(nums[i] == nums[i - 1])
				return true;
		return false;
	}
	//* perf: [5, 18]
	bool containsDuplicate_2(vector<int>& nums){
		std::set<int> s;
		for(auto e: nums){
			s.insert(e);
		}
		return s.size() != nums.size();
	}
};
