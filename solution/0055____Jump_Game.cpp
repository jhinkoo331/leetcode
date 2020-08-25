#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums){
		return _3(nums);
	}
private:
	/**
	 * @brief 5, 22
	 */
	bool _1(vector<int>& nums) {
		nums.back() = 1;
		for(int i = nums.size() - 2; i >= 0; --i){
			bool flag = false;
			for(int ii = 1; ii <= nums[i]; ++ii)
				if(nums[i + ii] == 1){
					flag = true;
					break;
				}
			nums[i] = flag;
		}
		return nums.front();
	}
	/**
	 * @brief 27, 21
	 * @time: O(n)
	 * @space: constant
	 */
	bool _2(vector<int>& nums){
		int left = 0, right = 0;
		int last_index = nums.size() - 1;
		while(left <= right && right < last_index){
			right = right > left + nums[left] ? right : left + nums[left];
			++left;
		}
		return right >= last_index;
	}
	/**
	 * @brief official solution approach 4
	 * @perf: 21, 40
	 */
	bool _3(vector<int>& nums){
		int left_good = nums.size() - 1;
		for(int i = nums.size() - 2; i >= 0; --i)
			if(i + nums[i] >= left_good)
				left_good = i;
		return left_good == 0;
	}
};


//TODO: solution
int main(){
	vector<int> v1 = {2, 3, 1, 1, 4};
	vector<int> v2 = {3, 2, 1, 0, 4};
	vector<int> v3 = {};
	Solution sln;
	sln.canJump(v1);
	sln.canJump(v2);
	sln.canJump(v3);
	return 0;
}