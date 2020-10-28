#include "util\frequently_included.h"

class Solution {
public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
                return _1(beginWord, endWord, wordList);
        }
private:
        /**
         * @brief tle
         */
        int _1(string& begin, string& end, vector<string>& wordList){
                unordered_set<string> us;
                for(auto str: wordList)
                        us.insert(str);
                vector<string> prev = {begin};
                vector<string> next;
                int ans = 1;
                while(prev.size()){
                        ++ans;
                        for(auto& e: prev)
                                us.erase(e);
                        for(auto s: us)
                                for(auto ss: prev)
                                        if(_1_adjcent_words(s, ss)){
                                                next.push_back(s);
                                                if(s == end)
                                                        return ans;
                                        }
                        prev.swap(next);
                        next.clear();
                }
                return false;
        }
        bool _1_adjcent_words(string& s, string& ss){
                bool same = true;
                for(int i = 0; i < s.size(); ++i)
                        if(s[i] != ss[i])
                                if(same)
                                        same = false;
                                else
                                        return false;
                return true;
        }
};

int main(){
        vector<string> arr = {"hot","dot","dog","lot","log","cog"};
        Solution sln;
        sln.ladderLength("hit", "cog", arr);
        return 0;
}
