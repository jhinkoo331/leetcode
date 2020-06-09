#include <vector>
using std::vector;

class Solution {
public:
	int removeDuplicates(vector<int>& nums){
		return removeDuplicates_2(nums);
	}
private:
	//* [55, 37]
	int removeDuplicates_1(vector<int>& nums){
		int free = 0;
		int i = 0;
		while(i < nums.size()){
			//* update `free`
			nums[free] = nums[i];
			free++;
			if(i + 1 < nums.size() && nums[i + 1] == nums[i]){
				i++;
				nums[free] = nums[i];
				free++;
			}
			while(i < nums.size() && nums[i] == nums[free - 1])
				i++;
		}
		return free;
	}
	//* [90, 27]
	int removeDuplicates_2(vector<int>& nums){
		int free = 0;
		for(const auto elem: nums){
			if(free < 2 || elem > nums[free - 2]){
				nums[free] = elem;
				free++;
			}
		}
		return free;
	}
};

int main(){
	vector<int> v = {1, 1, 1, 2, 2, 3};
	Solution sln;
	sln.removeDuplicates(v);
	return 0;
}