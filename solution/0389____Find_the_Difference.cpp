#include <set>
#include <string>
#include "util\frequently_included.h"
using std::string;
using std::multiset;


class Solution {
public:
        char findTheDifference(string s, string t) {
                return _1(s, t);
        }
private:
        /**
         * @perf: 5, 5
         */
        char _1(string s, string t){
                multiset<char> ms;
                for(int i = 0; i < t.size(); ++i)
                        ms.insert(t[i]);
                for(int i = 0; i < s.size(); ++i)
                        ms.erase(ms.find(s[i]));
                return *ms.begin();
        }

        /**
         * @brief 4ms, 20
         */
        char _2(string& s, string& t){
                vector<int> v(128, 0);
                for(auto e: s)
                        ++v[e];
                for(auto e: t)
                        --v[e];
                for(int i = 'a'; ; ++i)
                        if(v[i])
                                return i;
        }
};
