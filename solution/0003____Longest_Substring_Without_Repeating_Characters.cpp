#include "util\frequently_included.h"

class Solution {
public:
        int lengthOfLongestSubstring(string s){
                return _2(s);
        }
private:
        /**
         * @perf: 0ms, 96
         */
        int _1(string& s){
                bool exist[128] = {0};
                int left = 0, right = 0;                //* the substring is s[left, right)
                int sz = s.size();
                int max_len = 0;
                while(true){
                        if(right == sz){
                                max_len = max_len > right - left ? max_len : right - left;
                                break;
                        }
                        if(exist[s[right]] == 0)        // the substring's size increases by 1
                                exist[s[right]] = 1;
                        else{                           // duplicated, shrink the sub-string from left side
                                max_len = max_len > right - left ? max_len : right - left;
                                while(s[left] != s[right]){
                                        exist[s[left]] = 0;
                                        ++left;
                                }
                                ++left;
                        }
                        ++right;
                }
                return max_len;
        }

        /**
         * @perf: 98, 81
         */
        int _2(string& s){
                vector<int> v(128, -1);
                int max_len = 0;
                int left_index = -1;
                for(int i = 0; i < s.size(); ++i){
                        if(v[s[i]] > left_index)
                                left_index = v[s[i]];
                        v[s[i]] = i;
                        max_len = max(max_len, i - left_index);
                }
                return max_len;
        }
};

int main(){
        Solution sln;
        sln.lengthOfLongestSubstring("au");
        return 0;
}