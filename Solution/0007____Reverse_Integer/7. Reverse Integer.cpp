#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		if(x == INT32_MIN)			//! if x == INT32_MIN, it renders an bug with code (x = x < 0 ? -x : x)
			return 0;
		string s_int_max = to_string(INT32_MAX);
		string s_int_min = to_string(INT32_MIN);
		cout << s_int_max << ' ' << s_int_min << endl;
		// temporarily remove sign flag
		bool neg = x < 0;
		x = x < 0 ? -x : x;
		string s_x = to_string(x);
		while(s_x.size() < s_int_max.size())
			s_x.push_back('0');
		if(neg)
			s_x.push_back('-');
		std::reverse(s_x.begin(), s_x.end());
		if(neg && s_x > s_int_min || !neg && s_x > s_int_max)
			return 0;
		return stoi(s_x);
    }
};

int main(){

}


int main(){
	Solution sln;
	sln.reverse(0);
	return 0;
}