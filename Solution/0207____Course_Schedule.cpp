#include <vector>
#include <queue>
using std::vector;
using std::queue;

bool operator< (const vector<int>& v, const vector<int>& vv){
	return v.front() < vv.front();
}


class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		return canFinish_1(numCourses, prerequisites);
	}
private:
	/**
	 * ! perf: [31, 52]
	 * * Time: O(pre.size() + pre.size() + numCourse) => O(max(numCourses, pre.size()))
	 * * Space: O(numCourses + pre.size()) => O(max(numCourses, pre.size()))
	 */
	bool canFinish_1(int numCourses, vector<vector<int>>& pre){
		//* v[i] = j: there are still j courses to be finished before launching course i
		vector<int> v(numCourses, 0);
		//* vv[i][j]: j should launch after i finished
		vector<vector<int>> vv(numCourses);
		for(auto e: pre){
			v[e[1]]++;
			vv[e[0]].push_back(e[1]);
		}
		//* what courses could launch currently.
		queue<int> to_launch;
		for(int i = 0; i < numCourses; ++i)
			if(v[i] == 0)
				to_launch.push(i);
		while(!to_launch.empty()){
			int sz = to_launch.size();
			//* notice that every time we launch a group of courses.
			while(sz--){
				for(auto e: vv[to_launch.front()])
					if(--v[e] == 0)
						to_launch.push(e);
				to_launch.pop();
			}
		}
		//* if all elements in v are 0, all courses could be finished.
		for(auto e: v)
			if(e)
				return false;
		return true;
	}
};

int main(){
	vector<vector<int>> v = {{1, 0}, {0, 1}};
	Solution sln;
	sln.canFinish(2, v);
	return 0;
}
