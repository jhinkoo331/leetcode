#include "util\frequently_included.h"


class Cmp{
public:
        bool operator() (const string& s, const string& ss)const{
                return s + ss > ss + s;
        }
};

bool cmp(const string& s, const string& ss){
        return s + ss > ss + s;
}


class Solution {
public:
        string largestNumber(vector<int>& nums) {
                return _1(nums);

                multiset<string, Cmp> s_nums;
                for(const auto& elem: nums)
                        s_nums.insert(std::to_string(elem));
                string ret;
                for(auto itr = s_nums.begin(); itr != s_nums.end(); ++itr)
                        ret += *itr;
                int zero_count = 0;
                for(auto elem: ret)
                        if(elem == '0')
                                zero_count++;
                        else
                                break;
                return ret.substr(zero_count) == "" ? "0" : ret.substr(zero_count);		//* trim the leading 0s
        }

private:
        string _1(vector<int>& nums){
                unordered_multiset<string, Cmp> um;
                for(const auto& e: nums)
                        um.insert(std::to_string(e));
                string ans;
                for(const auto& e: um)
                        ans += e;
                int zero_count = 0;
                for(auto e: ans)
                        if(e == '0')
                                ++zero_count;
                        else
                                break;
                ans = ans.substr(zero_count);
                return ans == "" ? "0" : ans;
        }
        bool _1_all_zero(const string& s){
                for(int i = 0; i < s.size(); ++i)
                        if(s[i] != '0')
                                return false;
                return true;
        }
};

int main(){
        vector<int> v1 = {3, 30, 34, 5, 9};
        Solution sln;
        sln.largestNumber(v1);
        return 0;
}

