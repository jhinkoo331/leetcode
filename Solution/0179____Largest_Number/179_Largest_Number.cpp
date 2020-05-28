#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


class Cmp{
public:
	bool operator() (const string& s, const string& ss)const{
		return s + ss > ss + s;
	}
};


class Solution {
public:
	string largestNumber(vector<int>& nums) {
		multiset<string, Cmp> s_nums;
		for(const auto& elem: nums){
			s_nums.insert(to_string(elem));
		}
		string ret;
		for(auto itr = s_nums.begin(); itr != s_nums.end(); ++itr){
			ret += *itr;
		}
		int zero_count = 0;
		for(auto elem: ret){
			if(elem == '0'){
				zero_count++;
			}else{
				break;
			}
		}
		return ret.substr(zero_count) == "" ? "0" : ret.substr(zero_count);		//* trim the leading 0s
	}
};

int main(){
	vector<int> v1 = {3, 30, 34, 5, 9};
	Solution sln;
	sln.largestNumber(v1);
	return 0;
}

