#include "util\frequently_included.h"

class Solution {
public:
        string convertToBase7(int num) {
                return _1(num);
        }
private:
        /**
         * @perf: 4ms, 84
         */
        string _1(int num){
                bool negative = num < 0;
                num = abs(num);         //* num is guranteed in range [-1e7, 1e7]
                string ans;
                while(num){
                        ans.push_back(num % 7 + '0');
                        num /= 7;
                }
                if(negative)
                        ans += '-';
                reverse(ans.begin(), ans.end());
                //* 
                return ans.empty() ? "0" : ans;
        }
};

int main(){
        int i = 0x80000000;
        return 0;
}
