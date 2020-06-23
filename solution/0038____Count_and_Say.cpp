#include <string>
using std::string;


class Solution {
public:
	string countAndSay(int n) {
		return _1(n);
	}
private:
	/**
	 * @perf: [100, 89]
	 * 
	 * @param n 
	 * @return string 
	 */
	string _1(int n){
		string s = "1";
		while(--n){
			int ll = 0, rr = 0;
			string temp;
			while(ll != s.size()){
				while(rr < s.size() && s[rr] == s[ll])
					++rr;
				temp.push_back('0' + rr - ll);		//todo: prove that no overflow of digit
				temp.push_back(s[ll]);
				ll = rr;
			}
			s = temp;
		}
		return s;
	}
};

int main(){
	Solution sln;
	sln.countAndSay(30);
}

