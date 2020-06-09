#include <vector>
using std::vector;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		return lengthOfLIS_1(nums);
	}
private:
	/*
	 * perf: [70, 27]
	 * time: uncertain, worst: O(n^2)
	 * space: uncertain, worst: O(n)
	 */
	int lengthOfLIS_1(vector<int>& nums){
		vector<int> v;
		for(auto num: nums){
			bool flag = false;
			//TODO: use binary search to accelerate code below.
			for(auto& e: v)
				if(e >= num){
					e = num;
					flag = true;
					break;
				}
			if(!flag)
				v.push_back(num);
		}
		return v.size();
	}
};

int main(){
	vector<int> v = {10,9,2,5,3,7,101,18};
	Solution sln;
	sln.lengthOfLIS(v);
	return 0;
}