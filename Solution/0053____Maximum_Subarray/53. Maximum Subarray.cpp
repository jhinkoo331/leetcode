#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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
};

int main(){
	Solution sln;
	vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
	sln.maxSubArray(test);
	return 0;
}