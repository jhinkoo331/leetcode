#include <vector>
using namespace std;


class NumArray {
public:
	NumArray(vector<int>& nums) {
		this->info.resize(nums.size() + 1);
		info[0] = 0;
		for(int i = 1; i < info.size(); ++i){
			info[i] = info[i - 1] + nums[i - 1];
		}
	}
	int sumRange(int i, int j) {
		return this->info[j + 1] - this->info[i];
	}
private:
	vector<int> info;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


int main(){
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray sln(nums);
	int ret;
	ret = sln.sumRange(0, 2);
	ret = sln.sumRange(2, 5);
	ret = sln.sumRange(0, 5);
	return 0;
}