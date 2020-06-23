#include <string>
using std::string;

class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		return _1(s1, s2);
	}
private:
	/**
	 * @brief hash map
	 * @perf: [100, 100]
	 * @time: O(n), three-pass
	 * @space: constant
	 */
	bool _1(string& s1, string& s2){
		int map[128] = {0};
		for(int i = 0; i < s1.size(); ++i)
			++map[s1[i]];
		for(int i = 0; i < s2.size(); ++i)
			--map[s2[i]];
		for(int i = 0; i < 128; ++i)
			if(map[i] != 0)
				return false;
		return true;
	}
};
