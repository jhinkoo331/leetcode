#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using std::string;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		return _1(pattern, str);
	}
private:
	/**
	 * @brief 
	 * @perf: [100, 23]
	 */
	bool _1(string& pattern, string& str){
		std::stringstream ss;
		std::unordered_map<char, string> um;
		std::unordered_set<string> us;
		ss << str;
		for(auto e: pattern){
			if(!(ss >> str))
				return false;
			if(um.find(e) == um.end())
				if(us.find(str) == us.end()){
					um[e] = str;
					us.insert(str);
				}else
					return false;
			else if(str != um[e])
				return false;
		}
		return !(ss >> str);
	}
};
