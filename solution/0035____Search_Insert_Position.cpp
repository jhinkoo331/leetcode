#include <vector>
using std::vector;


//TODO discuss: https://leetcode.com/problems/search-insert-position/discuss/15080/My-8-line-Java-solution
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		return _2(nums, target);
	}
private:
	/**
	 * @brief traverse the array iteratively
	 * @perf: [89, 5]
	 * @time: O(n) on average
	 * @space: constant
	 */
	int _1(vector<int>& nums, int target){
		int i = 0;
		while(i < nums.size() && nums[i] < target)
			i++;
		return i;
	}
	/**
	 * @brief based on binary search
	 * @perf: [89, 41]
	 * @time: O(log(n))
	 * @space: constant
	 */
	int _2(vector<int>& nums, int target){
		//* two special cases
		if(nums.empty())
			return 0;
		//* nums[ll] < target, nums[rr] >= target
		int ll = 0, rr = nums.size() - 1;
		while(1){
			if(nums[ll] >= target)
				return ll;
			if(nums[rr] < target)
				return rr + 1;
			int mm = (rr - ll) / 2 + ll;
			if(nums[mm] >= target)
				rr = mm;
			else{
				ll = mm;
				//* this line is to reduce infinite loop in case such as [2, 10], target = 8;
				rr--;
			}
		}
	}
};

