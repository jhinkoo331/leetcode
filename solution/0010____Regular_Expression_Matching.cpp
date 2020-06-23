#include <string>
#include <set>
using std::set;
using std::string;

class Solution {
public:
	/**
	 * @brief '.' Matches any single character.
	 * @brief '*' Matches zero or more of the preceding element.
	 */
	bool isMatch(string s, string p) {
		return _1(s, p);
	}
private:
	/**
	 * @brief format pattern string.
	 * 
	 */
	void pre_process(string& s){
		string temp;
	}
	/**
	 * @brief 
	 * @perf: [77, 26]
	 * @param s 
	 * @param p 
	 * @return true 
	 * @return false 
	 */
	bool _1(string s, string p){
		set<int> index;
		index.insert(0);
		int i = 0;
		while(i < p.size()){
			if(index.empty())
				return false;
			if(i + 1 < p.size() && p[i + 1] == '*'){
				if(p[i] == '*'){
					//* two consecutive wildcard, ignore them
				}else if(p[i] == '.'){
					int temp = *index.begin();
					index.clear();
					while(temp <= s.size()){
						index.insert(temp);
						++temp;
					}
				}else{	//* zero or more p[i] char
					set<int> temp = index;
					for(auto e: index)
						while(e < s.size() && s[e] == p[i]){
							++e;
							temp.insert(e);
						}
					temp.swap(index);
				}
				i += 2;
			}else{
				if(p[i] == '*'){	//* skip

				}else if(p[i] == '.'){
					set<int> temp;
					for(auto e: index)
						if(e < s.size())
							temp.insert(e + 1);
					temp.swap(index);
				}else{
					set<int> temp;
					for(auto e: index)
						if(e < s.size() && s[e] == p[i])
							temp.insert(e + 1);
					temp.swap(index);
				}
				++i;
			}
		}
		return index.find(s.size()) != index.end();
	}
};

int main(){
	Solution sln;
	bool ans;
	ans = sln.isMatch("aa", "a");
	ans = sln.isMatch("aa", "a*");
	ans = sln.isMatch("ab", ".*");
	ans = sln.isMatch("aab", "c*a*b");
	ans = sln.isMatch("mississippi", "mis*is*p*.");
	return 0;
}