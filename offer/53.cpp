#include <vector>
using std::vector;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		return _1(nums, target);
	}

private:
	/**
	 * @brief binary search
	 * @perf: [64, 100]
	 */
	int _1(vector<int>& nums, int target){
		if(nums.empty())
			return 0;
		int left, right;
		//* try to find the first `target` in nums[ll, rr]
		int ll = 0, rr = nums.size() - 1;
		while(ll < rr){
			int mm = ll + (rr - ll) / 2;
			if(nums[mm] >= target)
				rr = mm;
			else
				ll = mm + 1;
		}
		if(nums[ll] == target)
			left = ll;
		else
			return 0;
		//* try to find the last `target` in nums[ll, rr]
		ll = 0, rr = nums.size() - 1;
		while(ll < rr){
			int mm = ll + (rr - ll + 1) / 2;
			if(nums[mm] <= target)
				ll = mm;
			else
				rr = mm - 1;
		}
		if(nums[ll] == target)
			right = ll;
		else
			return 0;

		return right - left + 1;
	}
};

