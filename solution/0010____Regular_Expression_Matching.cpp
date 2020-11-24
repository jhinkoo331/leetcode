#include <string>
#include "util\frequently_included.h"
#include <set>
using std::set;
using std::string;

class Solution {
public:
        /**
         * @brief '.' Matches any single character.
         * @brief '*' Matches zero or more of the preceding element.
         * @brief '.*' matches sequence of arbitrary length
         */
        bool isMatch(string s, string p) {
                return _2(s, p);
        }
private:
        /**
         * @brief format pattern string.
         * 
         */
        void pre_process(string& s){
                string temp;
        }
        /**
         * @brief 
         * @perf: [77, 26]
         */
        bool _1(string s, string p){
                unordered_set<int> index;
                index.insert(0);
                int i = 0;
                while(i < p.size()){
                        if(index.empty())
                                return false;
                        if(i + 1 < p.size() && p[i + 1] == '*'){
                                if(p[i] == '*'){
                                        //* two consecutive wildcard, ignore them
                                }else if(p[i] == '.'){
                                        int temp = *index.begin();
                                        index.clear();
                                        while(temp <= s.size()){
                                                index.insert(temp);
                                                ++temp;
                                        }
                                }else{	//* zero or more p[i] char
                                        unordered_set<int> temp = index;
                                        for(auto e: index)
                                                while(e < s.size() && s[e] == p[i]){
                                                        ++e;
                                                        temp.insert(e);
                                                }
                                        temp.swap(index);
                                }
                                i += 2;
                        }else{
                                if(p[i] == '*'){	//* skip

                                }else if(p[i] == '.'){
                                        unordered_set<int> temp;
                                        for(auto e: index)
                                                if(e < s.size())
                                                        temp.insert(e + 1);
                                        temp.swap(index);
                                }else{
                                        unordered_set<int> temp;
                                        for(auto e: index)
                                                if(e < s.size() && s[e] == p[i])
                                                        temp.insert(e + 1);
                                        temp.swap(index);
                                }
                                ++i;
                        }
                }
                return index.find(s.size()) != index.end();
        }
        /**
         * @brief 	.	any char
         * 		*	any count of preceding char
         * 		.*	any length of arbitrary char
         * @note	we assume that all pattern strings are valid, which means that
         * 		all * is following a non-star charactor, and * never appears
         * 		at the initial position of the pattern string
         * @perf:	0ms, 68
         */
        bool _2(string& s, string& p){
                if(p.empty())
                        return s.empty();
                vector<int> indices = {0};
                int dot_count = 0;		//* to merge consecutive dots operations
                for(int i = 0; i < p.size(); ){
                        if(indices.empty())
                                return false;
                        char c = p[i];
                        if(c == '*'){
                                //* pass
                        }else if(c == '.'){
                                if(i + 1 < p.size() && p[i + 1] == '*'){
                                        indices.resize(1);
                                        indices.front() += dot_count;
                                        if(indices.front() > s.size())
                                                return false;
                                        while(indices.back() < s.size())
                                                indices.push_back(indices.back() + 1);
                                        i += 2;
                                        dot_count = 0;
                                }else if(i + 1 < p.size() && p[i + 1] == '.'){
                                        ++dot_count;
                                        ++i;
                                }else{
                                        // process all consecutive dots
                                        ++dot_count;
                                        int rear = 0;
                                        for(auto index: indices){
                                                index += dot_count;
                                                if(index > s.size())
                                                        break;
                                                else{
                                                        indices[rear] = index;
                                                        ++rear;
                                                }
                                        }
                                        indices.resize(rear);
                                        dot_count = 0;
                                        ++i;
                                }
                        }else{		//* we meet a alphabetic char here
                                if(i + 1 < p.size() && p[i + 1] == '*'){
                                        vector<int> temp;
                                        for(auto index: indices){
                                                if(!temp.empty() && temp.back() >= index)
                                                        continue;
                                                temp.push_back(index);
                                                while(index < s.size() && s[index] == c){
                                                        ++index;
                                                        temp.push_back(index);
                                                }
                                        }
                                        indices.swap(temp);
                                        i += 2;
                                }else{
                                        int rear = 0;
                                        if(indices.back() == s.size())
                                                indices.pop_back();
                                        for(auto index: indices)
                                                if(s[index] == c){
                                                        indices[rear] = index + 1;
                                                        ++rear;
                                                }
                                        indices.resize(rear);
                                        ++i;
                                }
                        }
                }
                if(indices.empty() || indices.back() != s.size())
                        return false;
                else
                        return true;
        }
};


int main(){
        Solution sln;
        bool ans;
        // ans = sln.isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s");
        ans = sln.isMatch("aa", "a*");
        return 0;
}