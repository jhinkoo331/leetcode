#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class String{
public:
	string original_string;
	string later_string;
	bool is_prefix(String& s){
		if(s.later_string.size() >= this->later_string.size() && s.later_string.substr(0, this->later_string.size()) == this->later_string){
			s.later_string = s.later_string.substr(this->later_string.size());
			return true;
		}else{
			return false;
		}
	}
	bool operator< (const String& s) const{
		return later_string < s.later_string;
	}	
};


class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<String> v;
		for(const auto& elem: words){
			v.push_back({elem, elem});
		}
		bool flag = true;
		while(flag){
			flag = false;
			sort(v.begin(), v.end());
			for(int i = 0; i < v.size(); ++i){
				if(flag == true){
					break;
				}else if(v[i].later_string != ""){
					for(int ii = i + 1; ii < v.size(); ++ii){
						if(v[i].is_prefix(v[ii])){
							flag = true;
						}else{
							break;
						}
					}
				}
			}
		}
		vector<string> ret;
		for(const auto& elem: v){
			if(elem.later_string == ""){
				ret.push_back(elem.original_string);
			}
		}
		return ret;
	}
};


int main(){
	vector<string> v1 = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
	Solution sln;
	sln.findAllConcatenatedWordsInADict(v1);
	return 0;
}