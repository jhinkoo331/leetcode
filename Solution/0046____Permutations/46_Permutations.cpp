#include <vector>
#include <cstring>
#include <stack>
using namespace std;


class Solution {
public:
	//* in a recursive method
    vector<vector<int>> permute(vector<int>& nums) {
		this->nums = nums;
		this->valid.resize(nums.size(), 1);
		this->path.clear();
		this->paths.clear();
		if(nums.empty()){			//! critical, or it renders err when `nums` is empty: the return vector is not empty
			return this->paths;
		}
		this->get_permutation();
		return this->paths;
    }

private:
	vector<int> nums;
	vector<int> valid;
	vector<int> path;
	vector<vector<int>> paths;
	void get_permutation(){
		if(path.size() == nums.size()){		// this is a path
			paths.push_back(path);
		}else{				// search deeper
			for(int i = 0; i < nums.size(); ++i){
				if(valid[i]){
					valid[i] = false;
					path.push_back(nums[i]);
					get_permutation();
					valid[i] = true;
					path.pop_back();
				}
			}
		}
	}
};

int main(){
	Solution sln;
	vector<int> test = {1, 2, 3, 4, 5, 6, 7};
	vector<int> t = {};
	vector<int> tt = {1};
	sln.permute(t);
	sln.permute(tt);
	sln.permute(test);
	return 0;
}