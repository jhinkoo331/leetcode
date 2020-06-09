#include <vector>
#include <set>
#include <unordered_map>
#include <map>
using std::vector, std::unordered_map, std::multimap;


class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		return topKFrequent_1(nums, k);
	}
private:
	vector<int> topKFrequent_1(vector<int>& nums, int k){
		//* unordered_map<number, times>
		unordered_map<int, int> um;
		for(int e: nums){
			um[e]++;
		}
		//* map<times, number>
		multimap<int, int> m;
		for(auto e: um)
			m.insert({e.second, e.first});
		auto itr = m.begin();
		vector<int> ret;
		while(k--){
			ret.push_back(itr->second);
			++itr;
		}
		return ret;
	}
};

int main(){
	vector<int> v = {1, 1, 1, 2,2,3};
	Solution sln;
	sln.topKFrequent(v, 2);
	return 0;
}