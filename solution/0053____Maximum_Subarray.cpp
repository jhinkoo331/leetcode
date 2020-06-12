#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return _2(nums);
	}
private:
	int maxSubArray_1(vector<int>& nums) {
		int max_sum = INT_MIN;
			// set up the initial state of <left>, <right> and <cur_sum>
			int left = 0, right = 0;
			int cur_sum = 0;
			int sz = nums.size();
			while(true){
				if(right == sz)
					break;
				cur_sum += nums[right];
				max_sum = max_sum > cur_sum ? max_sum : cur_sum;		// update <max_sum>
				if(cur_sum < 0){	// data in range [nums[left], nums[right]] are all discarded.
					left = right + 1;
					cur_sum = 0;
				}
				right++;
			}
			return max_sum;
	}
	//! perf: [56, 14]
	//TODO: we may use the space of nums to store `sum` and `max` to reduce space used.
	int _2(vector<int>& nums){
		int sum = 0;
		int max = 0x80000000;
		for(int i = 0; i < nums.size(); ++i){
			sum += nums[i];
			if(sum > max)
				max = sum;
			if(sum < 0)
				sum = 0;
		}
		return max;
	}
};

int main(){
	Solution sln;
	vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
	sln.maxSubArray(test);
	return 0;
}