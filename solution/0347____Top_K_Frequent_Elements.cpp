#include "util\frequently_included.h"


class cmp {
public:
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
		return lhs.first < rhs.first;
	}
};
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		return _1(nums, k);
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

        vector<int> _1(vector<int>& nums, int k){
                sort(nums.begin(), nums.end());
                nums.push_back(nums.back() ^ 1);        // sentinel
                priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
                for(int i = 0; i != nums.size() - 1; ){
                        int ii = i;
                        while(nums[i] == nums[ii])
                                ii++;
                        if(pq.size() < k)
                                pq.push({ii - i, nums[i]});
                        else if(pq.top().first < ii - i){
				pq.pop();
				pq.push({ii - i, nums[i]});
			}
                        i = ii;
                }
                vector<int> ans;
                ans.reserve(k);
                while(pq.size()){
                        ans.push_back(pq.top().second);
                        pq.pop();
                }
                return ans;
        }
};

int main(){
	// vector<int> v = {1, 1, 1, 2,2,3};
	vector<int> v = {4,1,-1,2,-1,2,3};
	Solution sln;
	sln.topKFrequent(v, 2);
	return 0;
}