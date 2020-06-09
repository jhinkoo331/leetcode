#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->count = 0;
		this->result.clear();
		this->results.clear();
		if(n == 0){							//! critical
			return this->results;
		}
		this->get_results(n);
		return this->results;
    }
private:
	int count;
	string result;
	vector<string> results;
	void get_results(int n){
		if(n == 0){		//* a result found here
			string temp = result;
			for(int i = 0; i < count; ++i){
				temp.push_back(')');
			}
			results.push_back(temp);
		}else{
			if(count != 0){
				count--;
				result.push_back(')');
				get_results(n);
				count++;
				result.pop_back();
			}
			count++;
			result.push_back('(');
			get_results(n - 1);
			count--;
			result.pop_back();
		}
	}
};


int main(){
	Solution sln;
	sln.generateParenthesis(0);
	sln.generateParenthesis(1);
	sln.generateParenthesis(2);
	sln.generateParenthesis(3);
	sln.generateParenthesis(4);
	return 0;
}

