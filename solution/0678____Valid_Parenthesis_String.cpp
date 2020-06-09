#include <string>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
	bool checkValidString(string s) {
		
	}
private:
	bool checkValidString(string s){
		vector<char> v = {')'};
		for(auto e: s){
			switch (e)
			{
			case '*':
				if(v.back() == ')')
					v.push_back(e);
				else if(v.back() == '(')
					v.push_back
				break;
			
			default:
				break;
			}
		}
	}
};