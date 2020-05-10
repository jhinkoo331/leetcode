#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
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
};

int main(){
	string test = "()[]{}";
	Solution sln;
	sln.isValid(test);
	return 0;
}