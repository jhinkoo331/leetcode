#include "util\frequently_included.h"

class Solution {
public:
        vector<vector<string>> partition(string s) {
                _1(s);
                return ans;
        }

private:
        vector<vector<int>> info;
        vector<vector<string>> ans;
        vector<int> temp;
        string s;
        /**
         * @perf: 72, 74
         * TODO: iteratively rather than recursion
         */
        void _1(string& s){
                this->s = s;
                info.clear();
                ans.clear();
                temp.clear();
                _1_preprocess(s);
                _1_recursion(0);
        }
        void _1_preprocess(const string& s){
                info.resize(s.size());
                for(auto& e: info)
                        e = {0, 1};
                for(int len = 2; len <= s.size(); ++len)
                        for(int i = 0; i + len <= s.size(); ++i)
                                if(_1_exist(info[i + 1], len - 2) && s[i] == s[i + len - 1])
                                        info[i].push_back(len);
        }
        bool _1_exist(vector<int>& v, int target){
                if(v.back() == target || v[v.size() - 2] == target)
                        return true;
                else
                        return false;
        }
        void _1_recursion(int index){
                if(index == s.size())
                        _1_assemble();
                else
                        for(int i = 1; i < info[index].size(); ++i){
                                temp.push_back(info[index][i]);
                                _1_recursion(index + info[index][i]);
                                temp.pop_back();
                        }

        }
        void _1_assemble(){
                ans.push_back(vector<string>{});
                int i = 0;
                for(auto len: temp){
                        ans.back().push_back(s.substr(i, len));
                        i += len;
                }
        }
};

int main(){
        Solution sln;
        sln.partition("aab");
        return 0;
}