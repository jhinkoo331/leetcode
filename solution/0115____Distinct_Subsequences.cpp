#include "util\frequently_included.h"
class Solution {
public:
        int numDistinct(string s, string t) {
                return _3(s, t);
        }
private:
        /**
         * @perf: TLE
         */
        int _1(string& s, int ss, string& t, int tt){
                if(tt == t.size())
                        return 1;
                int count = 0;
                for(int i = ss; i < s.size(); ++i)
                        if(s[i] == t[tt])
                                count += _1(s, i + 1, t, tt + 1);
                return count;
        }

        /**
         * @perf: tle
         */
        vector<vector<int>> v;
        int count;
        int _2(string& s, string& t){
                v.resize(128);
                count = 0;
                for(int i = 0; i < s.size(); ++i)
                        v[s[i]].push_back(i);
                _2_helper(s, 0, t, 0);
                return count;
        }
        void _2_helper(string& s, int ss, string& t, int tt){
                if(tt == t.size()){
                        ++count;
                        return;
                }
                for(int i = 0; i < v[t[tt]].size(); ++i)
                        if(v[t[tt]][i] >= ss)
                                _2_helper(s, v[t[tt]][i] + 1, t, tt + 1);
        }
        /**
         * @perf: 0ms, 93
         */
        int _3(string& s, string& pattern){
                // v[c] stores all i where s[i] == c in increasing order
                vector<vector<unsigned>> v(128);
                for(unsigned i = 0; i < s.size(); ++i)
                        v[s[i]].push_back(i);

                // pair<index, count>
                vector<pair<int, unsigned>> info = {{-1, 1}};
                for(char c: pattern){
                        vector<unsigned> temp;
                        temp.reserve(v[c].size());
                        int info_index = 0;
                        for(int index: v[c]){
                                if(temp.empty())
                                        temp.push_back(0);
                                else
                                        temp.push_back(temp.back());
                                while(info_index < info.size() && info[info_index].first < index){
                                        temp.back() += info[info_index].second;
                                        ++info_index;
                                }
                        }
                        info.clear();
                        int temp_index = 0;
                        while(temp_index < temp.size() && temp[temp_index] == 0)
                                ++temp_index;
                        while(temp_index < temp.size()){
                                info.push_back({v[c][temp_index], temp[temp_index]});
                                ++temp_index;
                        }
                        if(info.empty())
                                break;
                }

                int sum = 0;
                for(int i = 0; i < info.size(); ++i)
                        sum += info[i].second;
                return sum;
        }
};

int main(){
        Solution sln;
        int i = -1;
        i = sln.numDistinct("abbbc", "abc");
        i = sln.numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac", "ceadbaa");
        i = sln.numDistinct("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc", "bcddceeeebecbc");
        return 0;	
}