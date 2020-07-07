#include <string>
#include <stack>
#include <algorithm>
using std::stack;
using std::string;
using std::reverse;


class Solution {
public:
	string reverseParentheses(string s) {
		return _1(s);
	}
private:
	/**
	 * @brief 
	 * @perf: [4ms, 74]
	 * @param s 
	 * @return string 
	 */
	string _1(string& s){
		stack<int> left;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '('){
				left.push(i);
			}else if(s[i] == ')'){
				reverse(s.begin() + left.top(), s.begin() + i);
				left.pop();
			}
		}
		string ss;
		for(int i = 0; i < s.size(); ++i)
			if(s[i] != '(' && s[i] != ')')
				ss += s[i];
		return ss;
	}
};
