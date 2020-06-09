#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		this->result.clear();
		this->results.clear();
		if(nums.empty()){					//! important
			return this->results;
		}
		this->valid.resize(nums.size(), 1);
		this->get_results(nums);
		return this->results;
    }
private:
	vector<int> result;
	vector<vector<int>> results;
	vector<int> valid;

	void get_results(const vector<int>& nums){
		if(result.size() == nums.size()){		//* this is a result!
			results.push_back(result);
			return;
		}
		bool first = 1;
		int last = 0;
		for(int i = 0; i < nums.size(); ++i){
			if(valid[i] && (first || nums[i] != last)){
				first = 0;
				last = nums[i];
				result.push_back(nums[i]);
				valid[i] = 0;
				//* search deeper
				get_results(nums);
				result.pop_back();
				valid[i] = 1;
			}
		}
	}
};


int main(){
	vector<int> v = {1, 2, 1};
	vector<int> vv = {};
	vector<int> vvv = {1};
	Solution sln;
	sln.permuteUnique(v);
	sln.permuteUnique(vv);
	sln.permuteUnique(vvv);
	return 0;
}