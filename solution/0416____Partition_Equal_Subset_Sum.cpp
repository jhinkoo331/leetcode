#include "util\frequently_included.h"

class Solution {
public:
        bool canPartition(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @perf: 6, 5
         */
        bool _1(vector<int>& nums){
                int sum = 0;
                for(auto num: nums)
                        sum += num;
                if(sum % 2 == 1)
                        return false;
                sum /= 2;
                unordered_set<int> us;
                us.insert(0);
                for(auto num: nums){
                        auto temp_us(us);
                        for(auto pre: temp_us)
                                if(pre + num == sum)
                                        return true;
                                else
                                        us.insert(pre + num);
                }
                return false;
        }
};