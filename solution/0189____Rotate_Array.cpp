#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	/**
	 * @brief Given an array, rotate the array to the right by k steps, where k is non-negative.
	 */
	void rotate(vector<int>& nums, int k) {
		_1(nums, k);
	}
private:
	/**
	 * @perf: [23, 96]
	 * @time: O(n);
	 * @space: in-place
	 */
	void _1(vector<int>& nums, int k){
		k %= nums.size();
		std::reverse(nums.begin(), nums.end() - k);
		std::reverse(nums.end() - k, nums.end());
		std::reverse(nums.begin(), nums.end());
		return;
	}
	/**
	 * @brief TODO Approach 3: Using Cyclic Replacements
	 * 
	 */
};