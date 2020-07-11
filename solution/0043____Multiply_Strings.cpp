#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	string multiply(string num1, string num2) {
		return _1(num1, num2);
	}
private:
	/**
	 * @perf: [99, 65]
	 */
	string _1(string& num1, string& num2){
		vector<int> v1, v2, ans;
		int first_non_zero;

		first_non_zero = 0;
		while(first_non_zero < num1.size() && num1[first_non_zero] == '0')
			++first_non_zero;
		if(first_non_zero == num1.size())
			return "0";
		v1.reserve(num1.size() - first_non_zero);
		for(int i = num1.size() - 1; i >= first_non_zero; --i)
			v1.push_back(num1[i] - '0');
		
		first_non_zero = 0;
		while(first_non_zero < num2.size() && num2[first_non_zero] == '0')
			++first_non_zero;
		if(first_non_zero == num2.size())
			return "0";
		v2.reserve(num2.size() - first_non_zero);
		for(int i = num2.size() - 1; i >= first_non_zero; --i)
			v2.push_back(num2[i] - '0');
		
		ans.resize(v1.size() + v2.size());
		for(int i = 0; i < v1.size(); ++i)
			for(int ii = 0; ii < v2.size(); ++ii)
				ans[i + ii] += v1[i] * v2[ii];
		//* format ans
		for(int i = 0; i < ans.size(); ++i){
			if(i + 1 < ans.size())
				ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if(ans.back() == 0)		//* there is at most one trailing zero
			ans.pop_back();
		string s;
		for(int i = ans.size() - 1; i >= 0; --i)
			s.push_back(ans[i] + '0');
		return s;
	}
};

int main(){
	Solution sln;
	// sln.multiply("2", "3");
	sln.multiply("123", "456");
	return 0;
}
