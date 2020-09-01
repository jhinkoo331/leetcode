#include "util\frequently_included.h"

class Solution {
public:
        vector<int> countBits(int num) {
                _1(num);
                return ans;
        }
private:
        vector<int> ans;
        void _1(int num){
                ans.resize(num + 1);
                ans.front() = 0;
                for(int i = 1; i <= num; ++i)
                        ans[i] = ans[i / 2] + i % 2;
        }
};