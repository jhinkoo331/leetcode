#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
        string longestCommonPrefix(vector<string>& strs){
                return _1(strs);
        }
private:
        /**
         * @brief 4ms, 87
         * 
         * @param strs 
         * @return string 
         */
        string _1(vector<string>& strs){
                if(strs.empty())
                        return "";
                int min_len = 0x7fffffff;
                for(int i = 0; i < strs.size(); ++i)
                        min_len = min_len < strs[i].size() ? min_len : strs[i].size();
                for(int i = 0; i < min_len; ++i)
                        for(int ii = 1; ii < strs.size(); ++ii)
                                if(strs[ii][i] != strs[0][i])
                                        return strs.front().substr(0, i);
                return strs.front().substr(0, min_len);
        }
        string _2(vector<string>& strs) {
                int min_len = INT_MAX;
                int len = 0;

                for(const auto& elem: strs)			// if `strs` is empty, `min_len` won't change.
                        min_len = min_len < elem.size() ? min_len : elem.size();
                if(strs.empty())
                        min_len = 0;
                if(min_len == 0)
                        return "";

                for(int i = 0; i < min_len; ++i){
                        char temp = strs.front()[len];
                        bool all_same = true;
                        for(const auto& elem: strs){
                                if(elem[len] != temp){
                                        all_same = false;
                                        break;
                                }
                        }
                        if(all_same)
                                len++;
                        else
                                break;
                }
                return strs.front().substr(0, len);			// what if strs.front() is empty
        }
};