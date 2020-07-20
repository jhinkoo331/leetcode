#include <vector>
using std::vector;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @brief 
	 * @perf: [35, 36]
	 * @param nums 
	 * @return int 
	 */
	int _1(vector<int>& nums){
		//* put nums[i] to the position of nums[nums[i]]
		for(int i = 0; i < nums.size(); ++i){
			while(nums[i] != nums.size() && nums[i] != i){	//* swap nums[i] and nums[nums[i]]
				int temp = nums[nums[i]];
				nums[nums[i]] = nums[i];
				nums[i] = temp;
			}
		}
		//* search the array
		int i = 0;
		nums.push_back(-1);	//* sentinel
		while(nums[i] == i)
			++i;
		nums.pop_back();
		return i;
	}
};

int main(){
	vector<int> v = {3,0,1};
	Solution sln;
	sln.missingNumber(v);
	return 0;
}