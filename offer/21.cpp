#include <vector>
using std::vector;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @brief left: odd, right: even
	 * @perf: [57, 100]
	 * @param nums 
	 * @return vector<int> 
	 */
	vector<int> _1(vector<int>& nums){
		int ll = 0, rr = nums.size() - 1;
		while(true){
			while(ll < nums.size() && nums[ll] % 2 == 1)
				++ll;
			while(rr >= 0 && nums[rr] % 2 == 0)
				--rr;
			if(ll < rr){
				int temp = nums[ll];
				nums[ll] = nums[rr];
				nums[rr] = temp;
			}else
				break;
		}
		return nums;
	}
};

int main(){
	vector<int> v = {1,2,3,4};
	Solution sln;
	sln.exchange(v);
	return 0;
}
