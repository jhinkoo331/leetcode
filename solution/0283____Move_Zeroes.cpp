#include <vector>
using std::vector;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		_1(nums);
	}
private:
	/**
	 * @perf: [92, 9]
	 * @time: O(n)
	 * @space: constant
	 * TODO: use swap to reduce operation
	 * @param nums 
	 */
	void _1(vector<int>& nums){
		int free = 0;
		for(auto e: nums)
			if(e != 0){
				nums[free] = e;
				++free;
			}
		while(free < nums.size()){
			nums[free] = 0;
			++free;
		}
	}
};
