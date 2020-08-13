#include <vector>
using std::vector;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @brief 	(3i + 1) 1 + (3j) 0 -> 1
	 * 		(3i + 1) 0 + (3j) 1 -> 0
	 * @perf: [78, 95]
	 */
	int _1(vector<int>& nums){
		int ans = 0;
		unsigned mask = 0x1;
		for(int i = 0; i < 32; ++i){
			int count = 0;
			for(int e: nums)
				if(e & mask)
					++count;
			if(count % 3 == 1)
				ans ^= mask;
			mask <<= 1;
		}
		return ans;
	}
	/**
	 * @brief no perf enhancement observed compared with method 1
	 * @perf: [78, 72]
	 */
	int _2(vector<int>& nums){
		unsigned ans = 0;
		unsigned mask = 0x1;
		for(int i = 0; i < 32; ++i){
			int count = 0;
			for(int ii = 0; ii < nums.size(); ++ii)
				if(nums[ii] & mask)
					++count;
			if(count % 3)
				ans ^= mask;
			mask <<= 1;
		}
		return ans;
	}
};

int main(){
	vector<int> v = {2,2,2,3};
	Solution sln;
	sln.singleNumber(v);
	return 0;
}