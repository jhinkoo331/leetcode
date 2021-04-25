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
                if(path.empty())
                        return "/";
                if(path.front() != '/')
                        path.insert(0, "/");
                if(path.back() != '/')
                        path.push_back('/');
                vector<string> s;
                vector<int> v;
                for(int i = 0; i < path.size(); ++i)
                        if(path[i] == '/')
                                v.push_back(i);
                for(int i = 1; i < v.size(); ++i){
                        string cur = path.substr(v[i - 1], v[i] - v[i - 1]);
                        if(cur == "/" || cur == "/.")
                                continue;
                        else if(cur == "/..")
                                if(!s.empty())
                                        s.pop_back();
                        else
                                s.push_back(cur);
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