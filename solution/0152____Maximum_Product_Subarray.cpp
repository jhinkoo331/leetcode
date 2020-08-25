#include <algorithm>
using std::max;
using std::min;
#include <vector>
using std::vector;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		return _1(nums);
	}
private:
	int ans;
	/**
	 * @brief 4ms, 20
	 * 
	 * @param nums 
	 * @return int 
	 */
	int _1(vector<int>& nums){
		nums.push_back(0);		//! sentinel
		ans = 0x80000000;
		int left = 0, right = 0, negative_count = 0;
		while(right < nums.size() - 1){
			if(nums[right] == 0){
				ans = max(ans, 0);
				negative_count = 0;
				++right;
			}else{
				left = right;
				while(nums[right] != 0){
					if(nums[right] < 0)
						++negative_count;
					++right;
				}
				_1_helper(nums, left, right, negative_count);
			}
		}
		return ans;
	}
	/**
	 * @brief
	 * 
	 * @param nums 
	 * @param left 
	 * @param right 
	 * @param negative_count 
	 * @return int: the max product in range nums[left, right)
	 */
	void _1_helper(vector<int>& nums, int left, int right, int negative_count){
		int product = 1;
		for(int i = left; i < right; ++i)
			product *= nums[i];

		if(negative_count % 2 == 0)
			ans = max(ans, product);
		else if(left + 1 == right)
			ans = max(ans, product);
		else{
			int left_product = 1;
			do{
				left_product *= nums[left];
			}while(nums[left++] > 0);
			int right_product = 1;
			//TODO: simplify logic here
			--right;
			do{
				right_product *= nums[right];
			}while(nums[right--] > 0);
			product /= max(left_product, right_product);
			ans = max(ans, product);
		}
	}
};

int main(){
	Solution sln;
	vector<int> v1 = {2,3,-2,4};
	sln.maxProduct(v1);
	return 0;
}