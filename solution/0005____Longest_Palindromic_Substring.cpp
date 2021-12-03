#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define yes 1
#define no 0

class Solution {
public:
    string longestPalindrome(string s) {
		memset(table, 0, sizeof(table));
		max_len = 1;
		j = 0;
		jj = 0;
		int len = s.size();
		for(int offset = 0; offset < len; ++offset){
			for(int i = 0; i < len - offset; ++i)
				check(i, i + offset, s);
		}
		return s.substr(j, jj - j + 1);		
    }
private:
	bool table[1000][1000];
	int max_len = 1;
	int j, jj;			//* first and last char of the indices of substr
	void check(int i, int ii, const string& s){		//! i <= ii
		if(s[i] == s[ii]){
			if(i == ii){
				table[i][ii] = yes;
			}else if(i + 1 == ii){
				table[i][ii] = yes;
				if(ii - i + 1 > max_len){
					max_len = ii - i + 1;
					j = i;
					jj = ii;
				}
			}else if(table[i + 1][ii - 1] == no){
				table[i][ii] = no;
			}else{
				table[i][ii] = yes;
				if(ii - i + 1 > max_len){
					max_len = ii - i + 1;
					j = i;
					jj = ii;
				}
			}
		}else{
			table[i][ii] = false;
		}
	}

	/**
	 * @brief 
	 * @time: n*n
	 * @space: n
	 */
	string _2(string& s){
		if(s.empty())
			return "";
		int max_len = 1;
		int max_len_start_index = 0;
		vector<bool> v(s.size() + 1, true);
		for(int len = 2; len <= s.size(); len += 2)
			for(int start_index = 0; start_index < s.size() - len + 1; ++start_index)
				if(v[start_index])
					if(s[start_index] == s[start_index + len - 1]){
						max_len = len;
						max_len_start_index = start_index;
					}else
						v[start_index] = false;
		vector<bool> v(s.size() + 1, true);
		for(int len = 3; len <= s.size(); len += 2)
			for(int start_index = 0; start_index < s.size() - len + 1; ++start_index)
				if(v[start_index])
					if(s[start_index] == s[start_index + len - 1]){
						if(len > max_len){
							max_len = len;
							max_len_start_index = start_index;
						}
					}else
						v[start_index] = false;
		return s.substr(max_len_start_index, max_len);
	}
};

int main(){
	string s = "abcda", ss = "cbbd";
	Solution sln;
	cout << sln.longestPalindrome(s) << endl;
	cout << sln.longestPalindrome(ss) << endl;
	return 0;
}