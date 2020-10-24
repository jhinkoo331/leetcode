#include "util\frequently_included.h"

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		return _2(s1, s2, s3);
	}
private:
	string s, ss, sss;
	bool _1(int i, int ii){
		int iii = i + ii;
		if(i == s.size())
			return ss.substr(ii) == sss.substr(iii);
		if(ii == ss.size())
			return s.substr(i) == sss.substr(iii);
		if(s[i] == sss[iii] && _1(i + 1, ii))
			return true;
		if(ss[ii] == sss[iii] && _1(i, ii + 1))
			return true;
		return false;
	}
	/**
	 * @perf: 4ms, 5
	 */
	bool _2(string& s, string& ss, string& sss){
		if(s.length() + ss.length() != sss.length())
			return false;
		unordered_set<int> us = {0};
		for(int iii = 0; iii < sss.size(); ++iii){
			unordered_set<int> new_us;
			if(us.empty())
				return false;
			for(auto i : us){
				if(i < s.length() && s[i] == sss[iii])
					new_us.insert(i + 1);
				if(iii - i < ss.length() && ss[iii - i] == sss[iii])
					new_us.insert(i);
			}
			us.swap(new_us);
		}
		return !us.empty();
	}
};

int main(){
	Solution sln;
	sln.isInterleave("aabcc", "dbbca", "aadbbbaccc");
	return 0;
}