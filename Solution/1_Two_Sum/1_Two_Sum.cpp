#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0xffffffff;
		data.resize(0x0000ffff + 1);			// todo: if don't plus 1, it renders Error on Leetcode...
		for(int i = 0; i < nums.size(); ++i){
			data[nums[i] & 0x0000ffff].push_back(make_pair(nums[i], i));
		}
		for(int i = 0; i < nums.size(); ++i){
			int couple = target - nums[i];				// nums[i] + couple == target
			int couple_col = couple & 0x0000ffff;		// `couple` is stored in data[couple_col]
			for(const auto& elem: data[couple_col]){
				if(elem.first + nums[i] == target && i != elem.second)		// solution found
					return vector<int> {i, elem.second};
			}
		}
		return vector<int> {};		// 'cuz there is always solution, this line is never reached, add this line to make compile pass.
    }
private:
	// pair<value, index>
	vector<vector<pair<int, int>>> data;
};


int main(){
	Solution sln;
	vector<int> nums = {2, 7, 11, 5};
	vector<int> numss = {3, 3};
	vector<int> numsss = {0, 4, 3, 0};
	vector<int> nums_4 = {-1, -2, -3, -4, -5};
	int target_4 = -8;
	int target = 9;
	// sln.twoSum(, 0);
	sln.twoSum(nums, 9);
	sln.twoSum(numsss, 0);
	sln.twoSum(nums_4, target_4);
	return 0;
}