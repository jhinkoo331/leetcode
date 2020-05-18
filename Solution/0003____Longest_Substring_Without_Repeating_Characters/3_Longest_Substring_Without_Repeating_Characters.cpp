#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s){
		if(s.empty())
			return 0;
		bool exist[128] = {0};
		int left = 0, right = 0;
		int sz = s.size();
		int max_len = 1;
		exist[s.front()] = 1;
		while(true){
			right++;			// try to expand the sub-string
			if(right == sz){
				max_len = max_len > right - left ? max_len : right - left;
				break;
			}
			if(exist[s[right]] == 0){		// the substring's size increases by 1
				exist[s[right]] = 1;
			}else{							// duplicated, shrink the sub-string from left side
				max_len = max_len > right - left ? max_len : right - left;
				while(s[left] != s[right]){
					exist[s[left]] = 0;
					left++;
				}
				left++;
			}
		}
		return max_len;
	}
};

int main(){
	Solution sln;
	sln.lengthOfLongestSubstring("au");
	return 0;
}