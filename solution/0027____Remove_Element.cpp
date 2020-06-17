#include <vector>
using std::vector;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		return _1(nums, val);
	}
private:
	/**
	 * @perf: [4ms, 24]
	 * 
	 * @param nums 
	 * @param val 
	 * @return int 
	 */
	int _1(vector<int>& nums, int val){
		int free = 0;
		for(int i = 0; i < nums.size(); ++i)
			if(nums[i] != val){
				nums[free] = nums[i];
				free++;
			}
		return free;
	}
};