#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int count = s.size();
		vector<vector<int>> v;
		v.resize(s.size());
		for(auto& elem: v)
			elem.resize(s.size(), 0);
		int step;
		// step = 1
		for(int i = 0; i < s.size(); ++i){
			v[i][i] = 1;
		}
		// step = 2
		for(int i = 0; i + 1 < s.size(); ++i){
			if(s[i] == s[i + 1]){
				v[i][i + 1] = 1;
				count++;
			}
		}
		for(step = 2; step < s.size(); ++step){
			int left = 0, right = step;
			while(right < s.size()){
				if(v[left + 1][right - 1] && s[left] == s[right]){
					v[left][right] = 1;
					count++;
				}
				left++;
				right++;
			}
		}
		return count;
	}
};

// I still love you !


int main(){
	Solution sln;
	sln.countSubstrings("abc");
	sln.countSubstrings("aaa");
	return 0;
}