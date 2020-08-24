#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s){
		return _2(s);
	}
private:
	//* perf: [23, 100]
	bool isValid_1(const string& s) {
		stack<char> ss;
		for(auto itr = s.begin(); itr != s.end(); ++itr){
			if(*itr == '(' | *itr == '[' | *itr == '{')
				ss.push(*itr);
			else{
				switch (*itr)
				{
				case ')':
					if(!ss.empty() && ss.top() == '(')
						ss.pop();
					else
						return false;	
					break;
				case ']':
					if(!ss.empty() && ss.top() == '[')
						ss.pop();
					else
						return false;
					break;
				case '}':
					if(!ss.empty() && ss.top() == '{')
						ss.pop();
					else
						return false;
					break;
				default:
					break;
				}
			}
		}
		if(ss.empty())
			return true;
		else
			return false;
	}
	
	/**
	 * @brief code-style enhanced
	 * @perf: 100, 100
	 */
	bool _2(const string& s){
		stack<char> stk;
		stk.push(')');			//* the stack is made never empty
		for(const auto& c: s)
			if(c == '(' | c == '[' | c == '{')
				stk.push(c);
			else
				switch(c){
				case ')':
					if(stk.top() == '(')
						stk.pop();
					else
						return false;
					break;
				case ']':
					if(stk.top() == '[')
						stk.pop();
					else
						return false;
					break;
				case '}':
					if(stk.top() == '{')
						stk.pop();
					else
						return false;
					break;
				}
		return stk.size() == 1;
	}
};

int main(){
	Solution sln;
	sln.isValid("()[]{}");
	return 0;
}