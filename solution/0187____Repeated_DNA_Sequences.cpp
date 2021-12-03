#include "util\frequently_included.h"
#include <iostream>

class Solution {
public:
        vector<string> findRepeatedDnaSequences(string s) {
                _1(s);
                return this->ans;
        }
private:
        vector<string> ans;
        const int len = 10;
        /**
         * @brief 
         * @perf: 51, 9
         */
        void _1(const string& s){
                unordered_map<string, int> us;
                for(int i = 0; i < ((int)s.size() - len + 1); ++i)
                        ++us[s.substr(i, len)];
                ans.clear();
                for(auto& e: us)
                        if(e.second > 1)
                                ans.push_back(e.first);
        }
};

int main(){
        Solution sln;
        sln.findRepeatedDnaSequences("");
        return 0;
}
