#include "util\frequently_included.h"

class Solution {
public:
        vector<int> grayCode(int n) {
                _1(n);
                return ans;
        }
private:
        /**
         * @brief 
         * @perf: 100, 70
         * @param n 
         */
        void _1(int n){
                ans = {0};
                for(int i = 0; i < n; ++i){
                        unsigned mask = 1 << i;
                        int ii = ans.size();
                        while(ii--)
                                ans.push_back(ans[ii] ^ mask);
                }
        }
        vector<int> ans;
};
