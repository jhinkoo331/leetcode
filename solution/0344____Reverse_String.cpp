#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	void reverseString(vector<char>& s) {
		_1(s);
	}
private:
	/**
	 * @perf: [40, 16]
	 * 
	 * @param s 
	 */
	void _1(vector<char>& s){
		std::reverse(s.begin(), s.end());
	}
};
