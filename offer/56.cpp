#include <unordered_set>
#include <vector>
using std::vector;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @brief 
	 * @perf: [16, 100]
	 * @time:
	 * @space: O(n/2) = O(n)
	 */
	vector<int> _1(vector<int>& nums){
		std::unordered_set<int> us;
		for(int i = 0; i < nums.size(); ++i){
			auto itr = us.find(nums[i]);
			if(itr == us.end())
				us.insert(nums[i]);
			else
				us.erase(itr);
		}
		return vector<int> {*(us.begin()), *(++us.begin())};
	}
	vector<int> _2(vector<int>& nums){
		int ans = 0;
		for(auto num: nums)
			ans ^= num;
		return ans;
	}
};
