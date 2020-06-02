#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums){
		return findDuplicate_5(nums);
	}
private:
	//* [80, 5]
	//* use the most significant bit to indicate whether the number has appeared
	int findDuplicate_1(vector<int>& nums) {
		for(int i = 0; i < nums.size(); ++i){
			int value = nums[i] & 0x7fffffff;
			if(nums[value] & 0x80000000){		//* duplicated found
				// reset(nums);			//* don't reset originally array to save CPU time
				return value;
			}
			nums[value] ^= 0x80000000;
		}
		return 0;					//* this line is never executed, just make program compilable.
	}
	void reset(vector<int>& nums){
		for(int i = 0; i < nums.size(); ++i){
			nums[i] &= 0x7fffffff;
		}
	}
	//* [64, 5]
	//* use a int array to store the info
	int findDuplicate_2(vector<int>& nums){
		vector<int> exist(nums.size(), 0);
		for(int i = 0; i < nums.size(); ++i){
			if(exist[nums[i]]){
				return nums[i];
			}else{
				exist[nums[i]] = 1;
			}
		}
		return 0;
	}
	//* [64, 5]
	//* use a bool vector rather than int vector
	int findDuplicate_3(vector<int>& nums){
		vector<bool> exist(nums.size(), false);
		for(int i = 0; i < nums.size(); ++i){
			if(exist[nums[i]] == true){
				return nums[i];
			}else{
				exist[nums[i]] = true;
			}
		}
		return -1;
	}
	//*
	//* use a set to store numbers
	int findDuplicate_4(vector<int>& nums){
		set<int> s;
		for(int i = 0; i < nums.size(); ++i){
			if(s.find(nums[i]) != s.end()){
				return nums[i];
			}else{
				s.insert(nums[i]);
			}
		}
		return -1;						//* make it compile
	}
	//* [80, 5]
	//* in-place algorithm
	int findDuplicate_5(vector<int>& nums){
		for(int i = 0; i < nums.size(); ++i){
			if(nums[i] != i){
				int num = nums[i];
				while(true){
					if(nums[num] == num & num != i){
						return num;		//* duplicated number found
					}else if(nums[num] == num & num == i){
						nums[num] = num;
						break;
					}else{
						int temp = nums[num];
						nums[num] = num;
						num = temp;
					}
				}
			}
		}
		return -1;
	}
	//* todo: Floyd's tortoise and hare alg.
};
