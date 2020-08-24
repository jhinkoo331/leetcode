#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
        bool isAnagram(string s, string t) {
                return _2(s, t);
        }
private:
        /**
         * @brief 28, 86
         * 
         * @param s 
         * @param t 
         * @return true 
         * @return false 
         */
        bool _1(string&s, string& t){
                sort(s.begin(), s.end());
                sort(t.begin(), t.end());
                return s == t;
        }
        /**
         * @brief 93, 17
         */
        bool _2(string&s, string& t){
                if(s.size() != t.size())                //* no effect to perf
                        return false;
                vector<int> v(128, 0);
                for(int i = 0; i < s.size(); ++i)
                        ++v[s[i]];
                for(int i = 0; i < t.size(); ++i)
                        --v[t[i]];
                for(int i = 0; i < 128; ++i)
                        if(v[i])
                                return false;
                return true;
        }
};

int main(){
        Solution sln;
        bool ret;
        ret = sln.isAnagram("hello", "llohe");
        ret = sln.isAnagram("thiss", "isth");
        return 0;
}