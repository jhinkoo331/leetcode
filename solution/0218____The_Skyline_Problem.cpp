#include <vector>
#include <set>
using std::vector;
using std::multiset;
using std::set;

class cmp{
public:
	bool operator() (const vector<int>& lhs, const vector<int> rhs) const {
		if(lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		//! 0 must be placed before 1
		else if(lhs[1] != rhs[1])
			return lhs[1] < rhs[1];
		else if(lhs[1] == 0)
		//! insert highest building firstly
			return lhs[2] > rhs[2];
		//! remove hightest building at last
		else
			return lhs[2] < rhs[2];
	}
};

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		return _1(buildings);
	}
private:
	/**
	 * @brief 
	 * !perf: [5, 7]
	 * @param buildings <left index, right index, height>
	 * @return vector<vector<int>> 
	 */
	vector<vector<int>> _1(vector<vector<int>>& buildings){
		// vector<time, in or out, height>
		multiset<vector<int>, cmp> ms;
		for(const auto& e: buildings){
			//* 0 for new building
			ms.insert(vector<int>{e[0], 0, e[2]});
			//* 1 for building ends
			ms.insert(vector<int>{e[1], 1, e[2]});
		}
		vector<vector<int>> ans;
		// map<height, count>
		multiset<int> s;
		s.insert(0);
		int pre_height = 0;
		for(auto e: ms){
			if(e[1] == 0){
				s.insert(e[2]);
			}else{
				//! s.erase(e[2]) will erase all element with value e[2]
				auto itr = s.find(e[2]);
				s.erase(itr);
			}
			int cur_height = *(s.rbegin());
			if(pre_height != cur_height){
				pre_height = cur_height;
				ans.push_back(vector<int>{e[0], pre_height});
			}
		}
		return ans;
	}
};

int main(){
	vector<vector<int>> v = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
	vector<vector<int>> vv = {{0,2,3},{2,5,3}};
	vector<vector<int>> vvv = {{1,2,1},{1,2,2},{1,2,3}};
	Solution sln;
	sln.getSkyline(v);
	sln.getSkyline(vv);
	sln.getSkyline(vvv);
	return 0;
}