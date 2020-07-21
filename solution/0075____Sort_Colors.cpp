#include <vector>
using std::vector; 

class Solution {
public:
	void sortColors(vector<int>& nums) {
		_1(nums);
	}
private:
	/**
	 * @brief in-place sorting, only 0, 1 and 2 in array
	 * @perf: [4ms, 81]
	 * @time: O(n)
	 * @space: in-place
	 */
	void _1(vector<int>& nums){
		int free_left = 0, free_right = nums.size() - 1;
		int left = 0, right = nums.size() - 1;
		while(left <= right){
			while(left <= right)
				if(nums[left] == 0){
					nums[left] = 1;
					nums[free_left++] = 0;
					++left;
				}else if(nums[left] == 1)
					++left;
				else
					break;
			while(left <= right)
				if(nums[right] == 0){
					break;
				}else if(nums[right] == 1){
					--right;
				}else{
					nums[right] = 1;
					nums[free_right--] = 2;
					--right;
				}
			if(left < right){
				nums[left++] = 1;
				nums[right--] = 1;
				nums[free_left++] = 0;
				nums[free_right--] = 2;
			}
		}
	}
};

int main(){
	Solution sln;
	vector<int> v = {2,0,2,1,1,0};
	sln.sortColors(v);
	return 0;
}