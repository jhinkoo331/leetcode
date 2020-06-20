#include <string>
using std::string;


class Solution {
public:
	int myAtoi(string str) {
		return _1(str);
	}
private:
	static const int k = 0x7fffffff / 10;
	/**
	 * @perf: [4ms, 19]
	 * @time: O(n), where n is the length of the string
	 * @space: constant
	 * @param str 
	 * @return int 
	 */
	int _1(string str){
		int i = 0;
		//* skip prevailing whitespaces
		while(i < str.size() && str[i] == ' ')
			i++;
		//* check optional sign flag
		int is_neg = false;
		if(i < str.size() && str[i] == '-')
			is_neg = true;
		if(i < str.size() && (str[i] == '-' || str[i] == '+'))
			i++;
		
		unsigned value = 0;
		//* while str[i] is valid
		while(i < str.size() && isdigit(str[i])){
			//* value * 10 would renders int overflow
			if(value > k)
				return is_neg ? 0x80000000 : 0x7fffffff;
			//* update value
			value *= 10;
			value += str[i] - '0';
			//* check overflow
			if(is_neg && value >= 0x80000000)
				return 0x80000000;
			else if(!is_neg && value >= 0x7fffffff)
				return 0x7fffffff;
			i++;
		}
		//* get the final answer
		int ans = is_neg ? -value : value;
		return ans;
	}
};

int main(){
	Solution sln;
	sln.myAtoi("-91283472332");
	sln.myAtoi("42");
	return 0;
}