#include <string>
using std::string;


class Solution {
public:
	bool isPalindrome(string s) {
		return _2(s);
	}
private:
	//* perf: [15, 13]
	bool _1(string s){
		string temp;
		for(auto e: s)
			if(isalnum(e))
				temp.push_back(tolower(e));
		int ll = 0, rr = temp.size() - 1;
		while(ll < rr){
			if(temp[ll] != temp[rr])
				return false;
			ll++;
			rr--;
		}
		return true;
	}
	//* perf: [32, 7]
	bool _2(string s){
		s = 'a' + s + 'a';
		int ll = 0, rr = s.size() - 1;
		while(ll < rr){
			while(!isalnum(s[ll]))
				ll++;
			while(!isalnum(s[rr]))
				rr--;
			if(tolower(s[ll]) != tolower(s[rr]))
				return false;
			ll++;
			rr--;
		}
		return true;
	}
};
