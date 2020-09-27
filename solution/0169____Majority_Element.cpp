#include "util\frequently_included.h"

class Solution {
public:
        /**
         * @perf: 96, 23
         */
        int majorityElement(vector<int>& nums) {
                int num;
                int count = 0;
                for(const auto& elem: nums){
                        if(count == 0){
                                num = elem;
                                count++;
                        }else if(elem == num)
                                count++;
                        else
                                count--;
                }
                return num;
        }
};
