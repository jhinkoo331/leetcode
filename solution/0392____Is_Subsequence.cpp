#include <string>
using std::string;

class Solution {
public:
	/**
	 * @brief check whther s is a subsequence of t
	 */
	bool isSubsequence(string s, string t) {
		return _1(s, t);
	}
private:
	/**
	 * @brief check elements in s one by one
	 * @perf: [4ms, 55]
	 * @time: O(sizeof(t))
	 * @space: constant
	 */
	bool _1(string s, string t){
		int cur = 0;
		//* the last element is sentinel
		t.push_back(0);
		for(auto e: s){
			if(cur == t.size())
				return false;
			t.back() = e;
			while(t[cur] != e)
				++cur;
			if(cur == t.size() - 1)
				return false;
			++cur;
		}
		return true;
	}

	//TODO 
	bool _2(string s, string t){
		int map[128];
		for(int i = 0; i < 128; ++i)
			map[i] = 0x7fffffff;
		for(int i = 0; i < t.size(); ++i)
			if(map[t[i]] == 0x7fffffff)
				map[t[i]] = i;
		
	}
};
int main(){
	bool ans;
	Solution sln;
	ans = sln.isSubsequence("abc", "ahbgdc");
	ans = sln.isSubsequence("axc", "ahbgdc");
	return 0;
}
