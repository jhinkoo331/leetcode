#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> mp;
		vector<vector<string>> v;
		for(const auto& elem: strs){
			string temp = elem;
			sort(temp.begin(), temp.end());
			mp[temp].push_back(elem);
		}
		for(const auto& elem: mp){
			v.push_back(elem.second);
		}
		return v;
	}
};

int main(){
	vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> vv = {};
	Solution sln;
	sln.groupAnagrams(v);
	sln.groupAnagrams(vv);
	return 0;
}
