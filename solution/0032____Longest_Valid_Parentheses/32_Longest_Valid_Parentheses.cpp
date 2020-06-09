#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    int longestValidParentheses_(string s) {
        int sz = s.size();
		vector<vector<int>> info(sz);
		for(int i = 0; i != sz; ++i)
			info[i].resize(sz, 0);
		int left = 0, right = 1;
		int max_len = 0;
		while(right < sz){
			if(s[left] == '(' && s[right] == ')'){
				info[left][right] = 1;
				max_len = 2;
			}
			left++;
			right++;
		}
		for(int len = 4; len <= sz; len += 2){
			left = 0, right = left + len - 1;
			while(right != sz){
				// check whether info[left][right] satisfies
				if(info[left + 1][right - 1] == 1 && s[left] == '(' && s[right] == ')'){
					info[left][right] = 1;
					max_len = len;
				}else{
					for(int temp = left + 1; temp < right; temp += 2){
						if(info[left][temp] && info[temp + 1][right]){
							info[left][right] = 1;
							max_len = len;
							break;
						}
					}
				}
				// shift the window
				left++;
				right++;
			}
		}
		return max_len;
    }

	int longestValidParentheses(string s){
		vector<pair<int, int>> v;
		this->init(s, v);
		this->check(s, v);
		return this->get_max_len(v);
	}
private:
	void init(const string& s, vector<pair<int, int>>& v){
		v.clear();
		for(int i = 0; i + 1 < s.size(); i++){
			if(s[i] == '(' && s[i + 1] == ')')
				v.push_back(make_pair(i, i + 1));
		}
	}
	bool check(const string& s, vector<pair<int, int>>& v, int i){
		// return `true` if `v` has been changed in this function
		bool big_flag = false;

		bool flag = true;
		while(flag){
			flag = false;
			while(i + 1 < v.size() && v[i].second + 1 == v[i + 1].first){	// merge
				flag = true;
				v[i].second = v[i + 1].second;
				v.erase(v.begin() + i + 1);
			}
			while(v[i].first - 1 >= 0 && s[v[i].first - 1] == '(' && v[i].second + 1 < s.size() && s[v[i].second + 1] == ')'){
				flag = true;
				v[i].first--;
				v[i].second++;
			}
			flag && (big_flag = true);
		}

		return big_flag;
	}
	bool check(const string& s, vector<pair<int, int>>& v){
		bool flag = true;
		while(flag){		// a loop
			flag = false;
			for(int i = 0; i < v.size(); ++i){
				check(s, v, i) && (flag = true);
			}
		}
		return true;
	}
	int get_max_len(const vector<pair<int, int>>& v){
		int max_len = 0;		// the real length is 1 more than max_len
		for(const auto& elem: v){
			max_len = max_len > elem.second - elem.first + 1? max_len : elem.second - elem.first + 1;
		}
		return max_len;
	}
};


int main(){
	Solution sln;
	sln.longestValidParentheses("");
	sln.longestValidParentheses(")(((((()())()()))()(()))(");
	sln.longestValidParentheses("()()()(()))()()())))((()()()(()()))(()()()((()()))())(((())()())(()(()(()(())(((()())()))(()))()))))()())(()))))()()(())()()((())()()))))((()))))(()()((()(()(()())((())()()()()))()()()(())()()())((((()(())())))(((()(((()((((())())(()()()()(((((()))()(()(())))(((()()()()(()(((())(()(()()(()(()(())()))))))()))()())((()((((()(())(()()()(((((()())()))))())))((((()()()(()(())(((())(((()()((()((()(((()(()))(((())(((()((((()(())(((()((()(()())))))(()(()()(())))))()(()()((()))()))())())((())))()(())((((()((()))))()())()))((()(()())()())()()((()))())(()(()(())((((((()()((((())))())(((()()())))()(((()(()()((((())))))()()((((()(()()())(()(())()()()((()(()((((())))((((((())(()())()))))(()(()))()))))))(()()((()()()())(())))(((()))(()()()(()))((())()()()())()()(((())(()(())()()(()())((()()(((((())(()((((()(()()()(()))(()((((())()())()())())))())(((()(()((())()()((((()()()()))))))())())()(((((()())()(()()()()()(((())((((((()))(())()(()())(()(()())(()(())))())))(()()(()((((()()(())(()))()))(()))(()())())()))))))()()(())))))()))()(()())))((())(()()))()((()))()(())()()((((())()))((()(()))()(((()())()(()()((()())((((())()))))()(())())())())(((()(()())))((()))))()())))))(()((())))()())((()))()()))(())())()))()()((()(((())()()()((()()(()(())(()))())())(((()())(()())(()((()()()())()(()(((((((()()(((()(((((((())(()))))())()))))))))()(()(()((((())(()()(((()))()(())(((((((((()(()())())()(((()((()(((()(()()(()))(())))))))(((");			//! this line renders Time Limit Exceeding error.
	sln.longestValidParentheses(")()())");
	sln.longestValidParentheses("");
	return 0;
}