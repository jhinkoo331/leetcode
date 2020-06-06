#include <string>
#include <stack>
#include <vector>
using std::string, std::stack, std::vector;


class Solution {
public:
	string simplifyPath(string path) {
		return simplifyPath_1(path);
	}
private:
	//* [66, 50]
	string simplifyPath_1(string path){
		path = '/' + path;
		path += '/';
		vector<string> s;
		vector<int> v;
		for(int i = 0; i < path.size(); ++i)
			if(path[i] == '/')
				v.push_back(i);
		for(int i = 0; i < v.size() - 1; ++i){
			string cur = path.substr(v[i], v[i + 1] - v[i]);
			if(cur == "/" || cur == "/."){
				//* pass
			}else if(cur == "/.."){
				if(!s.empty())
					s.pop_back();
			}else{
				s.push_back(cur);
			}
		}
		if(s.empty())
			return "/";
		else{
			string ret;
			for(auto e: s)
				ret += e;
			return ret;
		}
	}
};

int main(){
	Solution sln;
	sln.simplifyPath("/home/");
	sln.simplifyPath("/../");
	sln.simplifyPath("/home//foo/");
	sln.simplifyPath("/a/./b/../../c/");
	sln.simplifyPath("/a/../../b/../c//.//");
	sln.simplifyPath("/a//b////c/d//././/..");
	return 0;
}