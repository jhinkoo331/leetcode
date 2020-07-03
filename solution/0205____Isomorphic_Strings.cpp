#include <string>
using std::string;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		return _1(s, t);
	}
private:
	/**
	 * @brief 
	 * @perf: [98, 72]
	 */
	bool _1(string&s, string& t){
		if(s.size() != t.size())
			return false;
		//* map[i] = j: replace char i in s to j in t
		char map[128] = {0};
		bool mapped[128] = {0};
		for(int i = 0; i < s.size(); ++i){
			//* s[i] appears for the 1st time
			if(map[s[i]] == 0)
				//* the target char has already been mapped
				if(mapped[t[i]])
					return false;
				else{
					map[s[i]] = t[i];
					mapped[t[i]] = true;
				}
			else if(map[s[i]] != t[i])
				return false;
		}
		return true;
	}
};
