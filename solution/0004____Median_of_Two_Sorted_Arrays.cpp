#include <vector>
#include <algorithm>
using std::max;
using std::vector;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
	}
private:
	double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
		int target = nums1.size() >> 1 + nums2.size() >> 1 + nums1.size() & nums2.size() & 1;
		int l = 0, r = nums1.size() - 1;
		int ll = 0, rr = nums2.size() - 1;
		int m, mm;
		while(true){
			m = get_mid(l, r);
			mm = get_mid(ll, rr);
			if(m + mm + 2  == target){		//* how many numbers are in range [0, m] and [0, mm]
				return max(nums1[m], nums2[mm]);
			}else{
				
			}
		}
	}
	inline int get_mid(int i, int ii){
		return i >> 1 + ii >> 1 + i & ii & 1;
	}
};