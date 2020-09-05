#include "util\frequently_included.h"
class Solution {
public:
        string shortestPalindrome(string s) {
                return _2(s);
        }
private:
        /**
         * @brief brute force
         * @perf: tle err
         */
        string _1(string& s){
                for(int i = s.size() - 1; ; --i)
                        if(_1_is_palindrome(s, i)){
                                string temp = s.substr(i + 1);
                                reverse(temp.begin(), temp.end());
                                return temp + s;
                        }
        }
        bool _1_is_palindrome(const string& s, int right){
                int left = 0;
                while(left < right){
                        if(s[left] != s[right])
                                return false;
                        ++left;
                        --right;
                }
                return true;
        }

        vector<pair<char, int>> v;
        /**
         * @brief evolved from _1
         * @perf: 61, 88
         */
        string _2(string& s){
                if(s.empty())
                        return "";
                v.clear();
                v.push_back({s.front() ^ 1, 0});
                for(const auto e: s)
                        if(e == v.back().first)
                                ++v.back().second;
                        else
                                v.push_back({e, 1});
                int right = v.size() - 1;
                while(!_2_is_palindrome(right))
                        --right;
                int left_part_len = v[1].second;
                for(int i = 1; i < right; ++i)
                        left_part_len += v[i].second;
                string temp = s.substr(left_part_len);
                reverse(temp.begin(), temp.end());
                return temp + s;
        }
        bool _2_is_palindrome(int right){
                int left = 1;
                if(v[right].first != v[left].first || v[right].second < v[left].second)
                        return false;
                ++left;
                --right;
                while(left < right){
                        if(v[left] != v[right])
                                return false;
                        ++left;
                        --right;
                }
                return true;
        }
};

int main(){
        Solution sln;
        sln.shortestPalindrome("aacecaaa");
        return 0;
}