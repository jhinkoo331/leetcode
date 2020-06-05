#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		return addBinary_1(a, b);
	}
private:
	//* [84, 80]
	string addBinary_1(string a, string b){
		string ret;
		if(a.size() > b.size())
			b = string(a.size() - b.size(), '0') + b;
		else
			a = string(b.size() - a.size(), '0') + a;
		int carry = 0;
		for(int i = a.size() - 1; i >= 0; --i){
			int sum = a[i] - '0' + b[i] - '0' + carry;
			carry = sum >> 1;
			if(sum & 1)
				ret.push_back('1');
			else
				ret.push_back('0');
		}
		if(carry == 1)
			ret.push_back('1');
		while(!ret.empty() && ret.back() == '0')
			ret.pop_back();
		if(ret.empty())
			return "0";
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main(){
	Solution sln;
	sln.addBinary("11", "1");
	return 0;
}