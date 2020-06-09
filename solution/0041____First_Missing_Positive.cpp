#include <vector>
using std::vector;


class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		return firstMissingPositive_1(nums);
	}
private:
	/**
	 * ! perf: [100, 22]
	 */
	int firstMissingPositive_1(vector<int>& nums){
		nums.push_back(0);
		//* we should place nums in range [1, nums.size() - 1] to nums[index]
		int i = 0;
		while(i < nums.size()){
			if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != i && nums[nums[i]] != nums[i]){
				//* swap nums[i] and nums[nums[i]]
				int temp = nums[i];
				nums[i] = nums[nums[i]];
				nums[temp] = temp;
			}else{
				++i;
			}
		}
		i = 0;
		while(++i < nums.size())
			if(nums[i] != i)
				break;
		return i;
	}
};

int main(){
	vector<int> v = {7,8,9,11,12};
	vector<int> vv = {};
	vector<int> vvv = {1, 2, 0};
	Solution sln;
	int ans;
	ans = sln.firstMissingPositive(v);
	ans = sln.firstMissingPositive(vv);
	ans = sln.firstMissingPositive(vvv);
	return 0;
}