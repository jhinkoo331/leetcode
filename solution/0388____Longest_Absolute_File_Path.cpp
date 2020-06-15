#include <string>
#include <vector>
#include <stack>
using std::stack;
using std::vector;
using std::string;

/**
 * @brief split the string with "\n"
 * 
 * @param s the string to split
 * @param v store all substring, every string stands for a line
 */
void split(string& s, vector<string>& v){
	v.clear();
	if(s.empty())
		return;
	if(s.front() != '\n')
		s = '\n' + s;
	if(s.back() != '\n')
		s += '\n';
	vector<int> index;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '\n')
			index.push_back(i);
	for(int i = 1; i < index.size(); ++i)
		v.push_back(s.substr(index[i - 1] + 1, index[i] - index[i - 1] - 1));
}

/**
 * @brief count how many preceding tabs and erase them from the original string
 * 
 * @param s
 * @return int count of tabs
 */
int tab_count(string& s){
	int cur = 0;
	while(cur < s.size() && s[cur] == '\t')
		cur++;
	s = s.substr(cur, s.size() - cur);
	return cur;
}

/**
 * @brief check whether the token is for a file, a filename contains at least a '.' while dir name contains no '.'
 * 
 * @param s 
 * @return true s is file
 * @return false s is dir
 */
inline bool is_file(const string& s){
	return s.find('.') != std::string::npos;
}

class Solution {
public:
	int lengthLongestPath(string input) {
		return _1(input);
	}
private:
	//* perf: [4ms, 16]
	int _1(string input){
		vector<string> token;
		split(input, token);
		int max_len = 0;
		int cur_len = 0;
		stack<string> path;
		for(int i = 0; i < token.size(); ++i){
			int count = tab_count(token[i]);
			while(path.size() > count){
				cur_len -= path.top().size();
				path.pop();
			}
			if(path.empty())
				path.push(token[i]);
			else
				path.push('/' + token[i]);
			cur_len += path.top().size();
			if(is_file(path.top()))
				max_len = cur_len > max_len ? cur_len : max_len;
		}
		return max_len;
	}
};

int main(int argc, char const *argv[])
{
	Solution sln;
	sln.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
	return 0;
}
