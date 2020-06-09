#include <vector>
using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		return search_1(nums, target);
	}
private:
	int search_1(vector<int>& nums, int target){
		int left = 0, right = nums.size() - 1;
		while(left <= right){
			// int mid = (left + right) / 2;
			int mid = (right - left) / 2 + left;
			if(nums[mid] == target){
				return mid;
			}else if(nums[left] <= nums[right]){
				if(target < nums[mid]){
					right = mid - 1;
				}else{
					left = mid + 1;
				}
			}else if(nums[mid] >= nums[left]){		//* `mid` is in the left part
				if(target >= nums[left] && target < nums[mid]){
					right = mid - 1;
				}else{
					left = mid + 1;
				}
			}else{		//* nums[mid] <= nums[right]
				if(nums[mid] < target && target <= nums[right]){
					left = mid + 1;
				}else{
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};

int main(){
	vector<int> v = {4,5,6,7,0,1,2};
	vector<int> vv = {4,5,6,7,0,1,2};
	Solution sln;
	sln.search(v, 0);
	sln.search(v, 100);
	return 0;
}