#include <vector>
#include <stack>
using std::stack;
using std::vector;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		return _1(nums);
	}
private:
	/**
	 * @perf: 69, 76
	 */
	vector<int> _1(vector<int>& nums){
		stack<int> unfilled;
		vector<int> ans(nums.size(), -1);
		for(int i = 0; i < nums.size(); ++i){
			while(unfilled.size() && nums[unfilled.top()] < nums[i]){
				ans[unfilled.top()] = nums[i];
				unfilled.pop();
			}
			unfilled.push(i);
		}
		for(int i = 0; i < nums.size(); ++i){
			while(unfilled.size() && nums[unfilled.top()] < nums[i]){
				ans[unfilled.top()] = nums[i];
				unfilled.pop();
			}
			unfilled.push(i);
		}
		return ans;
	}
};

int main(){
	vector<int> v = {1, 2, 1};
	Solution sln;
	sln.nextGreaterElements(v);
	return 0;
}