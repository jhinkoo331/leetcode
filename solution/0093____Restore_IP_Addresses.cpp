#include <string>
#include <vector>
using std::vector;
using std::string;


class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		return _1(s);
	}
private:
	vector<int> v;		//* to store four strings' start indice
	vector<string> ans;
	/**
	 * @brief recursive
	 * @perf: [4ms, 15]
	 * @param s 
	 * @return vector<string> 
	 */
	vector<string> _1(string& s){
		v.reserve(4);
		_1_helper(s, 0, 4);
		return ans;
	}
	/**
	 * @brief 
	 * 
	 * @param s the string of the original IP string
	 * @param index the start index of the next string
	 * @param todo how many strings are todo
	 */
	void _1_helper(string& s, int index, int todo){
		if(todo == 0){
			if(index == s.size())
				_1_assemble(s);
			return;
		}
		int remain_digit = s.size() - index;		//* how many digits are avaliable now
		if(remain_digit < todo || remain_digit > todo * 3)
			return;
		v.push_back(index);
		//! only if the sub-string is of length 1, the leading number can be zero
		_1_helper(s, index + 1, todo - 1);
		if(s[index] != '0')
			_1_helper(s, index + 2, todo - 1);
		if(s[index] != '0' && s.size() - index >= 3 && stoi(s.substr(index, 3)) < 256)
			_1_helper(s, index + 3, todo - 1);
		v.pop_back();
	}
	void _1_assemble(string s){
		for(int i = 3; i > 0; --i)
			s.insert(v[i], ".");
		ans.push_back(s);
	}
};
