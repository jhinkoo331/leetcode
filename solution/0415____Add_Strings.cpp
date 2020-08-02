#include <string>
using std::string;
class Solution {
public:
	string addStrings(string num1, string num2) {
		return _1(num1, num2);
	}
private:
	/**
	 * @brief 
	 * @perf: 4ms, 73
	 * @param num1 
	 * @param num2 
	 * @return string 
	 */
	string _1(string& num1, string& num2){
		int carry = 0;
		//* let num1 be no shorter than num2
		if(num1.size() < num2.size())
			num1.swap(num2);
		int i = num1.size() - 1;
		int ii = num2.size() - 1;
		while(ii >= 0){
			int sum = num1[i] + num2[ii] + carry - '0' - '0';
			num1[i] = sum % 10 + '0';
			carry = sum / 10;
			--i;
			--ii;
		}
		if(carry == 0)
			return num1;
		while(i >= 0 && num1[i] == '9')
			num1[i--] = '0';
		if(i >= 0)
			++num1[i];
		else
			num1.insert(num1.begin(), '1');
		return num1;
	}
};

int main(){
	Solution sln;
	sln.addStrings("0", "0");
	return 0;
}