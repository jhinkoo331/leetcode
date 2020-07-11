#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	int romanToInt(string s) {
		return _1(s);
	}
private:
	int _1(string& s){
		char pre_char = s[0];
		int count = 1;
		int value = 0;

		s.push_back('a');
		for(int i = 1; i < s.size(); ++i){
			if(s[i] == pre_char)
				++count;
			else{
				switch (pre_char) {
				case 'I':
					if(s[i] == 'V' || s[i] == 'X')
						value -= 1 * count;
					else
						value += 1 * count;
					break;
				case 'X':
					if(s[i] == 'L' || s[i] == 'C')
						value -= 10 * count;
					else
						value += 10 * count;
					break;
				case 'C':
					if(s[i] == 'D' || s[i] == 'M')
						value -= 100 * count;
					else
						value += 100 * 100;
					break;
				case 'V':
					value += 5 * count;
					break;
				case 'L':
					value += 50 * count;
					break;
				case 'D':
					value += 500 * count;
					break;
				case 'M':
					value += 1000 * count;
					break;
				default:
					break;
				}
			}
		}
		return value;
	}

	/**
	 * @brief 
	 * @perf: [48, 92]
	 * @param s 
	 * @return int 
	 */
	int _2(string& s){
		//* end of the string
		s.push_back('E');
		int value = 0;
		for(int i = 0; i < s.size() - 1;){
			int ii = i + 1;
			switch (s[i]) {
			case 'I':
				while(ii < s.size() && s[ii] == 'I')
					++ii;
				if(s[ii] == 'V' || s[ii] == 'X')
					value -= (ii - i) * 1;
				else
					value += (ii  - i) * 1;
				i = ii;
				break;
			case 'V':
				value += 5;
				++i;
				break;
			case 'X':
				while(ii < s.size() && s[ii] == 'X')
					++ii;
				if(s[ii] == 'L' || s[ii] == 'C')
					value -= (ii - i) * 10;
				else
					value += (ii  - i) * 10;
				i = ii;
				break;
			case 'L':
				value += 50;
				++i;
				break;
			case 'C':
				while(ii < s.size() && s[ii] == 'C')
					++ii;
				if(s[ii] == 'D' || s[ii] == 'M')
					value -= (ii - i) * 100;
				else
					value += (ii  - i) * 100;
				i = ii;
				break;
			case 'D':
				value += 500;
				++i;
				break;
			case 'M':
				value += 1000;
				++i;
				break;
			default:
				break;
			}
		}
		return value;
	}
};

