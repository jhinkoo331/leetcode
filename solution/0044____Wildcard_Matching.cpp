#include <string>
#include <set>
#include <vector>
using std::string;
using std::set;

class Solution {
public:
	bool isMatch(string s, string p) {
		return _2(s, p);
	}
private:
	/**
	 * @brief pre process of pattern p, this function substitute all substring of * and ? with consecutive ? and a single *
	 */
	string pre_process(string& p){
		string pp;
		int cur = 0;
		while(cur < p.size()){
			while(cur < p.size() && isalpha(p[cur])){
				pp.push_back(p[cur]);
				cur++;
			}
			if(cur == p.size())
				break;
			int temp = cur;
			int ask_count = 0;			//* count of ?
			bool has_wildcard = false;		//* whether * has appeared
			for(; temp < p.size(); ++temp){
				if(p[temp] == '?')
					ask_count++;
				else if(p[temp] == '*')
					has_wildcard = true;
				else
					break;
			}
			pp += string(ask_count, '?');
			if(has_wildcard)
				pp.push_back('*');
			cur = temp;
		}
		return pp;
	}
	/**
	 * @brief Time Limit Exceeded
	 */
	bool _1(string s, string p){
		p = pre_process(p);
		return _1_helper(s, 0, p, 0);
	}
	bool _1_helper(const string& s, int ss, const string& p, int pp){
		string s_temp = s.substr(ss);
		string p_temp = p.substr(pp);
		if(pp == p.size())
			return ss == s.size();
		if(p[pp] == '?'){
			//* p[ppp] is the next non-? symbol or the end of p
			int ppp = pp + 1;
			while(ppp < p.size() && p[ppp] == '?')
				ppp++;
			//* ppp - pp = count of consecutive ?
			if(s.size() - ss < ppp - pp)
				return false;
			return _1_helper(s, ss + ppp - pp, p, ppp);
		}
		//* wildcard is the end or, followed by char
		if(p[pp] == '*'){
			if(pp == p.size() - 1)
				return true;
			else{
				int ppp = pp + 1;
				while(ppp < p.size() && isalpha(p[ppp]))
					++ppp;
				int len = ppp - pp - 1;
				for(int sss = ss; sss < s.size() - len + 1; ++sss)
					if(s.substr(sss, len) == p.substr(pp + 1, len))
						if(_1_helper(s, sss + len, p, ppp))
							return true;
				return false;
			}
		}
		while(pp < p.size() && isalpha(p[pp])){
			if(ss < s.size() && s[ss] == p[pp]){
				pp++;
				ss++;
			}else
				return false;
		}
		return _1_helper(s, ss, p, pp);
	}
	/**
	 * @perf: [49, 8]
	 */
	bool _2(string&s, string& p){
		p = pre_process(p);
		//* the start indices of substrings to be compared
		//* numbers in index are in range [0, index.size()]
		std::set<int> index;
		index.insert(0);
		for(int i = 0; i < p.size(); ++i){
			if(index.empty())
				return false;
			if(p[i] == '?'){	//* process consecutive ? at once
				int count = 1;
				while(i + 1 < p.size() && p[i + 1] == '?'){
					count++;
					i++;
				}
				set<int> temp;
				for(auto e: index)
					if(e + count <= s.size())
						temp.insert(e + count);
				temp.swap(index);
			}else if(p[i] == '*'){ //* wildcard is the end of p, or followed with char;
				if(i == p.size() - 1)
					return true;
				char target = p[i + 1];
				set<int> temp;
				for(int ii = *index.begin(); ii < s.size(); ++ii)
					if(s[ii] == target)
						temp.insert(ii);
				temp.swap(index);
			}else{		//* p[i] is char
				int ii = i;
				while(ii < p.size() && isalpha(p[ii]))
					++ii;
				string substr = p.substr(i, ii - i);
				int len = ii - i;
				i = ii - 1;
				set<int> temp;
				for(auto e: index)
					if(e + len <= s.size() && s.substr(e, len) == substr)
						temp.insert(e + len);
				temp.swap(index);
			}
		}
		return index.find(s.size()) != index.end();
	}
};



int main(){
	Solution sln;
	bool ans;
	string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
	string ss = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
	ans = sln.isMatch("abc", "abc*def");
	ans = sln.isMatch("cb", "?a");
	ans = sln.isMatch("adceb", "*a*b");
	ans = sln.isMatch("acdcb", "a*c?b");
	ans = sln.isMatch(s, ss);
	return 0;
}
