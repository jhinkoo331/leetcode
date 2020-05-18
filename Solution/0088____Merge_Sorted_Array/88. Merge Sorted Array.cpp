#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
		int cur = m + n - 1;
		int cur_1 = m - 1;
		int cur_2 = n -1;
		while(cur_1 >= 0 && cur_2 >= 0){
			if(nums1[cur_1] > nums2[cur_2]){
				nums1[cur] = nums1[cur_1];
				cur--;
				cur_1--;
			}else{
				nums1[cur] = nums2[cur_2];
				cur--;
				cur_2--;
			}
		}
		if(cur_2 >= 0){
			while(cur_2 >= 0){
				nums1[cur_2] = nums2[cur_2];
				cur_2--;
			}
			//* this way works as well
			// memcpy(nums1.data(), nums2.data(), sizeof(int) * (1 + cur_2));
		}
    }
};