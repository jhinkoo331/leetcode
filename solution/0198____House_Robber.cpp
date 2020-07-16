#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution {
public:
	int rob(vector<int>& nums) {
		return _2(nums);
	}
private:
	/**
	 * @perf: [100, 32]
	 * @time: O(n)
	 * @space: O(3n) = O(n)
	 */
	int _1(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return max(nums[0], nums[1]);

		/**
		 * @brief: the is no consecutive 3 houses that not robbed
		 * @take: the max we may get if we take nums[i]
		 * @take_no_take: the max we may get if we don't take nums[i]
		 */
		vector<int> take(nums.size()), take_no_take(nums.size()), no_take_no_take(nums.size());
		take[0] = nums[0];
		take_no_take[0] = 0;
		no_take_no_take[0] = 0;
		take[1] = nums[1];
		take_no_take[1] = nums[0];
		no_take_no_take[1] = 0;
		for(int i = 2; i <nums.size(); ++i){
			take[i] = nums[i] + max(take_no_take[i - 1], no_take_no_take[i - 1]);
			take_no_take[i] = take[i - 1];
			no_take_no_take[i] = take[i - 2];
		}
		return max(take.back(), take_no_take.back());
	}

	/**
	 * @brief evolved from _1, use constant extra spaces
	 * @perf: [100, 96]
	 * @time: O(n)
	 * @space: constant
	 */
	int _2(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return max(nums[0], nums[1]);

		int take_notake = nums[0], notake_notake = 0;
		for(int i = 2; i <nums.size(); ++i){
			nums[i] = nums[i] + max(take_notake, notake_notake);
			take_notake = nums[i - 1];
			notake_notake = nums[i - 2];
		}
		return max(nums.back(), take_notake);
	}
};

int main(){
	vector<int> v1 = {1,2,3,1};
	Solution sln;
	sln.rob(v1);
	return 0;
}