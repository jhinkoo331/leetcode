#include <vector>
using namespace std;

class Solution {
public:
	//* `nums` is guaranteed positive
	bool canJump(vector<int>& nums) {
		nums.back() = 1;
		for(int i = nums.size() - 2; i >= 0; --i){
			bool flag = false;
			for(int ii = 1; ii <= nums[i]; ++ii){
				if(nums[i + ii] == 1){
					flag = true;
					break;
				}
			}
			nums[i] = flag;
		}
		return nums.front();
	}
};


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