#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::stringstream;

class Solution {
public:
	string reverseWords(string s) {
		return _1(s);
	}
private:
	/**
	 * @brief 
	 * @perf: [82, 29]
	 * @param s 
	 * @return string 
	 */
	string _1(string& s){
		stringstream ss;
		ss << s;
		string temp;
		string ans;
		//TODO enhance extra memory
		vector<string> v;
		while(ss >> temp){
			v.push_back(temp);
		}
		for(int i = v.size() - 1; i >= 0; --i)
			ans += v[i] + ' ';
		if(!ans.empty())
			ans.pop_back();
		return ans;
	}
};

int main(){
	Solution sln;
	sln.reverseWords("");
	return 0;
}