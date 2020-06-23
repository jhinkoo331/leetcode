#include <vector>
#include <stack>
#include <string>
using std::string;
using std::vector;
using std::stack;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		return _1(tokens);
	}
private:
	/**
	 * @perf: [72, 70]
	 * 
	 * @param tokens 
	 * @return int 
	 */
	int _1(vector<string>& tokens){
		stack<int> s;
		for(const auto& e: tokens)
			if(e == "+"){
				int temp = s.top();
				s.pop();
				s.top() += temp;
			}else if(e == "-"){
				int temp = s.top();
				s.pop();
				s.top() -= temp;
			}else if(e == "*"){
				int temp = s.top();
				s.pop();
				s.top() *= temp;
			}else if(e == "/"){
				int temp = s.top();
				s.pop();
				s.top() /= temp;
			}else
				s.push(stoi(e));
		return s.top();
	}
};
