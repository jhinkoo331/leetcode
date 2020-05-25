#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty()){
			return 0;
		}
		int next_free = 1;
		for(int i = 1; i < nums.size(); ++i){
			if(nums[i] == nums[i - 1]){
				//* do nothing
			}else{
				nums[next_free] = nums[i];
				next_free++;
			}
		}
		return next_free;
	}
};

int main(){
	vector<int> v1 = {1, 1, 2};
	vector<int> v2 = {0,0,1,1,1,2,2,3,3,4};
	vector<int> v3 = {};
	Solution sln;
	int ret;
	ret = sln.removeDuplicates(v1);
	ret = sln.removeDuplicates(v2);
	ret = sln.removeDuplicates(v3);
	return 0;
}