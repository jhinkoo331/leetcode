#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	int strStr(string haystack, string needle) {
		return _1(haystack, needle);
	}
private:
	/**
	 * @perf: [4ms, 54]
	 * @time: O(mn)
	 * @space: constant
	 */
	int _1(const string& haystack, const string& needle){
		int diff = haystack.size() - needle.size();
		for(int i = 0; i <= diff; ++i)
			if(haystack.substr(i, needle.size()) == needle)
				return i;
		return -1;
	}
	/**
	 * @brief KMP
	 * 
	 */
	int _2(const string& haystack, const string& needle){

	}
	void helper_2(const string& needle, vector<int>& v){
		v.resize(needle.size());

	}
};
