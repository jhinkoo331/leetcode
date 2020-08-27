#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		return _1(nums, k);
	}
private:
	/**
	 * @brief same with Approach 4: Using Hashmap
	 * @perf: 62, 22
	 */
	int _1(vector<int>& nums, int k){
		std::unordered_map<int, int> um;
		um[0] = 1;
		int sum = 0;
		int ans = 0;
		for(int i = 0; i < nums.size(); ++i){
			sum += nums[i];
			ans += um[sum - k];
			++um[sum];
		}
		return ans;
	}

	/**
	 * @brief same w/ Approach 2, 3: Using accumulative sum and w/o extra space
	 * @perf: TLE
	 */
	int _2(vector<int>& nums, int k){
		for(int i = 1; i < nums.size(); ++i)
			nums[i] += nums[i - 1];
		int ans = 0;
		for(int i = 0; i < nums.size(); ++i){
			if(nums[i] == k)
				++ans;
			for(int ii = 0; ii < i; ++ii)
				if(nums[i] - nums[ii] == k)
					++ans;
		}
		return ans;
	}
};

int main(){
	vector<int> v1 = {1,1,1};
	Solution sln;
	sln.subarraySum(v1, 2);
	return 0;
}
