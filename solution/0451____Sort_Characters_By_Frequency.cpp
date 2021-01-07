#include "util\frequently_included.h"

class Solution {
public:
        string frequencySort(string s) {
                _1(s);
                return s;
        }
private:
        /**
         * @brief we use the original s to store the answer
         * @perf: 88, 88
         * @time: n
         * @space: 1
         */
        void _1(string& s){
                int fre[128] = {0};
                for(int i = 0; i < s.size(); ++i)
                        ++fre[s[i]];
                s = "";
                // pair<frequency, char>
                pair<int, char> temp[128];
                for(int i = 0; i < 128; ++i)
                        temp[i] = {fre[i], i};
                sort(temp, temp + 128);
                for(int i = 127; i >= 0; --i)
                        while(temp[i].first--)
                                s += temp[i].second;
                return;
        }
};

int main(){
        Solution sln;
        sln.frequencySort("abbccc");
        return 0;
}

