#include <string>
#include <sstream>
using namespace std;


class Solution {
public:
	int lengthOfLastWord(string s) {
		return lengthOfLastWord_1(s);
	}
private:
	//* [71, 5]
	int lengthOfLastWord_1(string s){
		stringstream ss;
		ss << s;
		string temp;
		while(ss >> temp);
		return temp.size();
	}
};
