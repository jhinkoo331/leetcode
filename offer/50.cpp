#include <string>

class Solution {
public:
        char firstUniqChar(string s) {
                return _1(s);
        }
private:
        /**
         * @brief 96,5 
         */
        char _1(string s){
                int reg['z' - 'a' + 1] = {0};
                for(auto c: s)
                        ++reg[c - 'a'];
                for(auto c: s)
                        if(reg[c - 'a'] == 1)
                                return c;
                return ' ';       // no such char detected
        }
};