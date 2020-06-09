#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums){
		vector<int> v;
		vector<int> temp;
		if(nums.empty()){
			return v;
		}
		vector<int> valid(nums.size(), true);
		sort(nums.begin(), nums.end());
		bool has_1 = false;
		if(nums.front() == 1){
			has_1 = true;
			valid[0] = false;
		}
		for(int i = 1; i < nums.size(); ++i){
			if(valid[i] == true){
				int temp = nums[]
				for(int ii = )
			}
		}
	}
};