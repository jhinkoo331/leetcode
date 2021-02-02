#include <vector>
using std::vector;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @brief 
	 * 
	 * @param nums 
	 * @return int 
	 */
	int _1(vector<int>& nums){
		if(nums.size() == 1)
			return nums[0];
		if(nums.size() == 2)
			return nums[0] < nums[1] ? 1 : 0;
		if(nums[0] > nums[1])
			return 0;
		if(nums[nums.size() - 2] < nums[nums.size() - 1])
			return nums.size() - 1;
		//* there must be a answer in range [ll, rr]
		int ll = 0, rr = nums.size() - 1;
		while(true){

		}
	}
};