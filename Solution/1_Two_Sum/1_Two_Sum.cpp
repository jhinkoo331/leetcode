#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum_1(vector<int>& nums, int target) {
		data.resize(0x00010000);
		int sz = nums.size();
		for(int i = 0; i != sz; ++i){
			data[nums[i] & 0x0000ffff].push_back(make_pair(nums[i], i));
		}
		for(int i = 0; i != sz; ++i){
			int couple = target - nums[i];				// nums[i] + couple == target
			int couple_col = couple & 0x0000ffff;		// `couple` is stored in data[couple_col]
			for(const auto& elem: data[couple_col]){
				if(elem.first == couple && i != elem.second)		// solution found
					return vector<int> {i, elem.second};
			}
		}
		return vector<int> {};		// 'cuz there is always solution, this line is never reached, add this line to make compile pass.
    }
	vector<int> twoSum(vector<int>& nums, int target){
		data.resize(16);
		int sz = nums.size();
		for(int i = 0; i != sz; ++i)
			data[nums[i] & 0xf].push_back(make_pair(nums[i], i));
		for(int i = 0; i != sz; ++i){
			int couple = target - nums[i];
			int couple_col = couple & 0xf;
			int sz_2 = data[couple_col].size();
			for(int ii = 0; ii != sz_2; ++ii){
				if(data[couple_col][ii].first == couple && i != data[couple_col][ii].second)
					return vector<int> {i, data[couple_col][ii].second};
			}
		}
		return vector<int> {};
	}
private:
	// pair<value, index>
	vector<vector<pair<int, int>>> data;
};


int main(){
	int i = sizeof(pair<int, int>);
	Solution sln;
	vector<int> nums = {-3, 4, 3, 90};
	vector<int> numss = {3, 3};
	vector<int> numsss = {0, 4, 3, 0};
	vector<int> nums_4 = {-1, -2, -3, -4, -5};
	int target_4 = -8;
	int target = 9;
	// sln.twoSum(, 0);
	sln.twoSum(nums, 0);
	sln.twoSum(numsss, 0);
	sln.twoSum(nums_4, target_4);
	return 0;
}