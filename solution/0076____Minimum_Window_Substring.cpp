#include "util\frequently_included.h"

class Solution {
public:
        string minWindow(string s, string t) {
                return "";
        }
private:
        /**
         * @brief 
         * @perf: 99, 14
         * @param s 
         * @param t 
         * @return string 
         */
        string _1(string& s, string& t){
                s.push_back(0);         // sentinel, the last char in s is not in t
                vector<int> v(128, 0);
                int neg_count = 0;
                for(auto c: t)
                        if(!(v[c]--))
                                ++neg_count;
                int left = 0, right = 0;
                int start, len = 0x7fffffff;
                while(right < s.size()){
                        while(right < s.size() && neg_count){
                                ++v[s[right]];
                                if(v[s[right]] == 0)
                                        --neg_count;
                                ++right;
                        }
                        if(right == s.size())
                                break;
                        while(neg_count == 0){
                                --v[s[left]];
                                if(v[s[left]] == -1)
                                        ++neg_count;
                                ++left;
                        }
                        int temp_len = right - left + 1;
                        if(temp_len < len){
                                len = temp_len;
                                start = left - 1;
                        }
                }
                if(len == 0x7fffffff)
                        return "";
                else
                        return s.substr(start, len);
        }
};
