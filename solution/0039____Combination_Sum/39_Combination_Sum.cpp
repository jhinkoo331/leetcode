#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		result.clear();
		results.clear();
		sort(candidates.begin(), candidates.end());
		this->get_result(candidates, 0, target);
		return this->results;
	}
private:
	vector<int> result;
	vector<vector<int>> results;

	void get_result(const vector<int>& candidates, int first, int target){
		if(target == 0){	//* this is a result
			results.push_back(result);
			return;
		}
		if(first >= candidates.size()){
			return;
		}
		if(target < 0){
			return;
		}
		get_result(candidates, first + 1, target);
		result.push_back(candidates[first]);
		get_result(candidates, first, target - candidates[first]);
		result.pop_back();
	}
};


int main(){
	vector<int> v = {2, 3, 6, 7};
	Solution sln;
	sln.combinationSum(v, 7);
	return 0;
}

