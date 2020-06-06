#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	int numDecodings(string s) {
		return numDecodings_2(s);
	}
private:
	//* Time Limit Exceeded..
	int numDecodings_1(string& s){
		if(s.empty())
			return 0;
		int count = 0;
		helper_1(s, 0, count);
		return count;
	}
	void helper_1(string& s, int head, int& count){
		if(head == s.size()){
			count++;
			return;
		}
		if(s[head] == '0')
			return;
		helper_1(s, head + 1, count);
		if(head + 1 < s.size() && (s[head] == '1'| s[head] == '2' & s[head + 1] < '7'))
			helper_1(s, head + 2, count);
	}
	//* [4ms, 69]
	int numDecodings_2(string& s){
		if(s.empty() || s.front() == '0')
			return 0;
		if(s.size() == 1)
			return 1;
		vector<int> v = {1, 1};
		for(int i = 1; i < s.size(); ++i){
			switch (s[i - 1]) {
				case '0':
					if(s[i] == '0')				//* two consecutive zero -> no solution
						return 0;
					else
						v.push_back(v[i]);		//* no digit can be connected after zero
					break;
				case '1':
					if(s[i] == '0'){
						v.push_back(v[i - 1]);
					}else{
						v.push_back(v[i - 1] + v[i]);
					}
					break;
				case '2':
					if(s[i] == '0'){
						v.push_back(v[i - 1]);
					}else if(s[i] <= '6'){
						v.push_back(v[i - 1] + v[i]);
					}else{
						v.push_back(v[i]);
					}
					break;
				default:
					if(s[i] == '0'){
						return 0;
					}else{
						v.push_back(v[i]);
					}
					break;
			}
		}
		return v.back();
	}
};

int main(){
	Solution sln;
	sln.numDecodings("12");
	sln.numDecodings("7541387519572282368613553811323167125532172369624572591562685959575371877973171856836975137559677665");
	return 0;
}

// "7541387519572282368613553811323167125532172369624572591562685959575371877973171856836975137559677665"
