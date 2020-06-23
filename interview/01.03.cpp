#include <string>
using std::string;

class Solution {
public:
	string replaceSpaces(string S, int length) {
		return _1(S, length);
	}
private:
	/**
	 * @perf: [93, 100]
	 * 
	 * @param S 
	 * @param length 
	 * @return string 
	 */
	string _1(string& S, int length){
		int free = S.size() - 1;
		for(int i = length - 1; i >= 0; --i)
			if(S[i] == ' '){
				S[free--] = '0';
				S[free--] = '2';
				S[free--] = '%';
			}else{
				S[free--] = S[i];
			}
		//* there are unused space at head
		return S.substr(free + 1);
	}
};

int main(){
	Solution sln;
	sln.replaceSpaces("a b c       ", 6);
	sln.replaceSpaces("Mr John Smith    ", 13);
	sln.replaceSpaces("ds sdfs afs sdfa dfssf asdf             ", 27);
}
