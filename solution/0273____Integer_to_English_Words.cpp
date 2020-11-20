#include "util\frequently_included.h"

const string words[] = {"", "One ", "Two ", "Three ", "Four ", "Five ",
                        "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
                        "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
                        "Eighteen ", "Nineteen "};
const string ten[] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ",
                        "Seventy ", "Eighty ", "Ninety "};

class Solution {
public:
        string numberToWords(int num) {
                return _1(num);
        }
private:
        /**
         * @perf: 4ms, 79, 62
         */
        string _1(int num){
                // special condition, or it would retrun an empty string on 0
                if(num == 0)
                        return "Zero";
                vector<string> v;
                bool flag;
                if(num)
                        _1_helper(num, v);
                if(num){
                        if(num % 1000)
                                v.push_back("Thousand ");
                        _1_helper(num, v);
                }
                if(num){
                        if(num % 1000)
                                v.push_back("Million ");
                        _1_helper(num, v);
                }
                if(num){
                        if(num % 1000)
                                v.push_back("Billion ");
                        _1_helper(num, v);
                }
                string ans;
                for(int i = v.size() - 1; i >= 0; --i)
                        ans += v[i];
                ans.pop_back();
                return ans;
        }
        void _1_helper(int& num, vector<string>& v){
                int remainder = num % 100;
                int hundred = (num % 1000) / 100;
                num /= 1000;
                if(remainder < 20)
                        v.push_back(words[remainder]);
                else {
                        v.push_back(words[remainder % 10]);
                        v.push_back(ten[remainder / 10]);
                }
                if(hundred != 0){
                        v.push_back("Hundred ");
                        v.push_back(words[hundred]);
                }
        }
};

int main(){
        Solution sln;
        // sln.numberToWords(2147483647);
        sln.numberToWords(12345);
        return 0;
}

