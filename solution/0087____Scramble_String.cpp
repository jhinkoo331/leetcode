#include <string>
#include <vector>
using std::string;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		return _1(s1, s2);
	}
private:
	bool _1(string& s1, string& s2){
		if(s1.empty() || s2.empty())
			return false;
		if(!_1_is_permutation(s1, s2))
			return false;
		return _1_is_scramble(s1, 0, s2, 0, s1.size());
	}
	bool _1_is_permutation(string& s1, string& s2){
		if(s1.size() != s2.size())
			return false;
		std::vector<int> v(128);
		for(int i = 0; i < s1.size(); ++i)
			++v[s1[i]];
		for(int i = 0; i < s2.size(); ++i)
			--v[s2[i]];
		for(int i = 'A'; i < v.size(); ++i)	//* only charactors need to be checked
			if(v[i] != 0)
				return false;
		return true;
	}
	bool _1_is_scramble(string& s1, int index1, string& s2, int index2, int len){
		if(s1.substr(index1, len) == s2.substr(index2, len))
			return true;
		std::vector<int> v(128);
		int non_zero_count = 0;
		//* i + 1 is the size of left part of s1 and size of right part of s2
		for(int i = 0; i < len - 1; ++i){
			++v[s1[index1 + i]];
			if(v[s1[index1 + i]] == 1)
				++non_zero_count;
			else if(v[s1[index1 + i]] == 0)
				--non_zero_count;
			--v[s2[index2 + len - 1 - i]];
			if(v[s2[index2 + len - 1 - i]] == 0)
				--non_zero_count;
			else if(v[s2[index2 + len - 1 + i]] == -1)
				++non_zero_count;
			if(non_zero_count == 0 && _1_is_scramble(s1, index1, s2, index2 + len - i - 1, i + 1) && _1_is_scramble(s1, index1 + i + 1, s1, index2, len - i - 1));
				return true;
		}
		return false;
	}
};

int main(){
	Solution sln;
	sln.isScramble("abcde", "caebd");
	return 0;
}