#include <vector>
#include <set>
#include <algorithm>
using namespace  std;

bool operator< (const vector<int>& lhs, const vector<int>& rhs) {
	if(lhs[0] != rhs[1])
		return lhs[0] < rhs[0];
	return lhs[1] < rhs[1];
}

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end());
		vector<vector<int>> new_pairs;
		for(auto& elem: pairs){
			while(!new_pairs.empty() && new_pairs.back()[1] >= elem[1])
				new_pairs.pop_back();
			new_pairs.push_back(elem);
		}
		int last_rear = 0;
		int count = 0;
		for(const auto& elem: new_pairs){
			if(elem[0] >= last_rear){
				count++;
				last_rear = elem[1];
			}
		}
		return count;
	}
};