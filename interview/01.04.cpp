#include <string>
using std::string;


class Solution {
public:
	bool canPermutePalindrome(string s) {
		return _1(s);
	}
private:
	/**
	 * @perf: [100, 100] 
	 * @param s 
	 * @return true 
	 * @return false 
	 */
	bool _1(string& s){
		bool table[128] = {0};
		for(int i = 0; i < s.size(); ++i)
			table[s[i]] ^= 1;
		int count = 0;
		for(int i = 0; i < 128; ++i)		//TODO: better perf
			if(table[i])
				count++;
		return count <= 1;
	}
};
