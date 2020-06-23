#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		s.clear();
		v.clear();
		if(!digits.empty())
			_1(digits, 0);
		return v;
	}
private:
	string s;
	vector<string> v;
	const vector<string> info = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	/**
	 * @perf: [100, 83]
	 * TODO: non-recursive
	 * @param digits 
	 * @param i 
	 */
	void _1(string& digits, int i){
		if(i == digits.size()){
			v.push_back(s);
			return;
		}
		for(int ii = 0; ii < info[digits[i] - '0'].size(); ++ii){
			s.push_back(info[digits[i] - '0'][ii]);
			_1(digits, i + 1);
			s.pop_back();
		}
	}
};

int main(){
	Solution sln;
	sln.letterCombinations("23");
}