#include <set>
#include <string>
#include <algorithm>
using std::string;

class Solution {
public:
	bool isUnique(string astr) {
		return _4(astr);
	}
private:
	/**
	 * @perf: [100, 100]
	 * @brief sort the string and compare one by one
	 * @time: sort: O(nlog_n); compare: o(n); total: O(n log_n)
	 * @space: constant
	 */
	bool _1(string& astr){
		std::sort(astr.begin(), astr.end());
		for(int i = 1; i < astr.size(); ++i)
			if(astr[i - 1] == astr[i])
				return 0;
		return 1;
	}
	/**
	 * @brief use set to store chars in the string, check whether the char exists already before inserting it into set
	 * @perf: [100, 100]
	 * @time: O(nlog_n)
	 * @space: O(n)
	 */
	bool _2(string& astr){
		std::set<int> s;
		for(auto e: astr){
			if(s.find(e) != s.end())
				return false;
			s.insert(e);
		}
		return true;
	}
	/**
	 * @brief dual traverse
	 * @perf: [100, 100]
	 * @time: o(n^2)
	 * @space: in-place
	 */
	bool _3(string& astr){
		for(int i = 0; i < astr.size(); ++i)
			if(i != astr.find_last_of(astr[i]))
				return false;
		return true;
	}
	/**
	 * @brief Premise: all symbols are lower ASCII char, 26 in total. We use a 32bit integer to make a hash map
	 * @note: try to reduce the size of hash map
	 * @perf: [100, 100]
	 * @time: O(n)
	 * @space: constant
	 */
	bool _4(string& astr){
		unsigned map = 0;
		for(auto e: astr){
			unsigned temp = 1 << (e - 'a');
			if((map & temp) != 0)
				return false;
			map |= temp;
		}
		return true;
	}
};

int main(){
	Solution sln;
	sln.isUnique("iluhwpyk");
	return 0;
}
