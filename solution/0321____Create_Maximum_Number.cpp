#include <vector>
using std::vector;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		return maxNumber_1(nums1, nums2, k);
	}
private:
	vector<int> maxNumber_1(vector<int>& nums1, vector<int>& nums2, int k){
		int p1 = 0, p2 = 0;
		vector<int> ret;
		int total_offset = nums1.size() + nums2.size() - k;
		while(k--){
			int max_value = -1;
			//* the offset between the number we choose and the p pointer of the array
			int offset = -1;
			bool max_in_nums1;
			for(int ii = 0; ii <= total_offset && p1 + ii < nums1.size(); ++ii){
				if(nums1[p1 + ii] > max_value){
					max_value = nums1[p1 + ii];
					offset = ii;
					max_in_nums1 = true;
				}
			}
			for(int ii = 0; ii <= total_offset && p2 + ii < nums2.size(); ++ii){
				if(nums2[p2 + ii] > max_value){
					max_value = nums2[p2 + ii];
					offset = ii;
					max_in_nums1 = false;
				}
			}
			if(max_in_nums1){
				ret.push_back(nums1[p1 + offset]);
				p1 += offset + 1;
			}else{
				ret.push_back(nums2[p2 + offset]);
				p2 += offset + 1;
			}
			total_offset -= offset;
		}
		return ret;
	}
};

int main(int argc, char const *argv[]) {
	vector<int> v = {8, 9};
	vector<int> vv = {3, 9};
	Solution sln;
	sln.maxNumber(v, vv, 3);
	return 0;
}
