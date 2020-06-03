#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		return jump_2(nums);
	}
private:
	//* time limit exceeded
	int jump_1(vector<int>& nums){
		if(nums.empty()){	//todo
			return 0;
		}
		nums.back() = 0;
		for(int i = nums.size() - 2; i >= 0; --i){
			if(nums[i] == 0){
				nums[i] = 0x7fffffff;
			}else{
				int temp = i + nums[i] + 1 < nums.size() ? i + nums[i] + 1 : nums.size();
				int _min = *min_element(nums.begin() + i + 1, nums.begin() + temp);
				if(_min != 0x7fffffff){
					nums[i] = 1 + _min;
				}else{
					nums[i] = 0xfffffff;
				}
			}
		}
		return nums.front();
	}
	//* [52, 5]
	//* we can take the vector as a tree, and this algorithm is bfs...
	int jump_2(vector<int>& nums){
		if(nums.size() < 2){
			return 1;
		}
		int step = 0;
		int ll = 0, rr = 0;		//* left and right
		while(true){
			step++;			//* we take a step!
			int new_rr = 0;		//* the hightest stair we may reach in this step
			for(int i = ll; i <= rr; ++i){
				new_rr = max(new_rr, i + nums[i]);
				if(new_rr >= nums.size() - 1){		//* we have reach the top stair
					return step;
				}
			}
			ll = rr + 1;
			rr = new_rr;
		}
		return -1;
	}
};

int main(){
	vector<int> v = {2, 3, 1, 1, 4};
	vector<int> vv = {1,1,1,1};
	vector<int> vvv = {5,9,3,2,1,0,2,3,3,1,0,0};
	Solution sln;
	int i = sln.jump(v);
	i = sln.jump(vv);
	i = sln.jump(vvv);
	return 0;
}