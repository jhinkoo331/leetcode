#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if(s3.size() != s1.size() + s2.size()){
			return false;
		}
		s = s1;
		ss = s2;
		sss = s3;
		i = ii = iii = 0;
		return check();
	}

private:
	string s, ss, sss;
	int i, ii, iii;
	bool check(){
		if(i == s.size()){
			if(ss.substr(ii) == sss.substr(iii)){
				return true;
			}else{
				return false;
			}
		}
		if(ii == ss.size()){
			if(s.substr(i) == sss.substr(iii)){
				return true;
			}else{
				return false;
			}
		}
		if(s[i] == sss[iii]){
			i++;
			iii++;
			if(check())
				return true;
			i--;
			iii--;
		}
		if(ss[ii] == sss[iii]){
			ii++;
			iii++;
			if(check())
				return true;
			ii--;
			iii--;
		}
		return false;
	}
};


int main(){
	Solution sln;
	bool ans = sln.isInterleave("aabcc", "dbbca", "aadbbcbcac");
	return 0;
}