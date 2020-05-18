#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int min_len = INT_MAX;
		int len = 0;

		for(const auto& elem: strs)			// if `strs` is empty, `min_len` won't change.
			min_len = min_len < elem.size() ? min_len : elem.size();
		if(strs.empty())
			min_len = 0;
		if(min_len == 0)
			return "";

		for(int i = 0; i < min_len; ++i){
			char temp = strs.front()[len];
			bool all_same = true;
			for(const auto& elem: strs){
				if(elem[len] != temp){
					all_same = false;
					break;
				}
			}
			if(all_same)
				len++;
			else
				break;
		}
		return strs.front().substr(0, len);			// what if strs.front() is empty
    }
};