#include <set>
#include <string>
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
};