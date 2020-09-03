#include "util\frequently_included.h"

class Solution {
public:
	int singleNumber(vector<int>& nums){
		return _2(nums);
	}
private:
	/**
	 * @brief 98, 35
	 */
	int _1(vector<int>& nums) {
		for(int i = 1; i < nums.size(); ++i)
			nums[0] ^= nums[i];
		return nums[0];
	}
	/**
	 * @brief 93, 80
	 */
	int _2(vector<int>& nums){
		int temp = 0;
		for(auto e: nums)
			temp ^= e;
		return temp;
	}
};