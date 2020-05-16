#include <vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		for(int i = 0; i < nums.size(); ++i){
			int value = nums[i] & 0x7fffffff;
			if(nums[value] & 0x80000000){		// duplicated found
				reset(nums);
				return value;
			}
			nums[value] ^= 0x80000000;
		}
		return 0;								//* this line is never executed, just make program compilable.
	}
private:
	void reset(vector<int>& nums){
		for(int i = 0; i < nums.size(); ++i){
			nums[i] &= 0x7fffffff;
		}
	}
};