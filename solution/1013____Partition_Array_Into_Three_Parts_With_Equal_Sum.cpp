#include "util\frequently_included.h"

class Solution {
public:
        bool canThreePartsEqualSum(vector<int>& A) {
                return _1(A);
        }
private:
        /**
         * @brief two pass
         * @perf: 76, 53
         * @time: 2n
         * @space: 1
         */
        bool _1(vector<int>& A){
                int sum = _1_sum(A);
                if(sum % 3 != 0)
                        return false;
                int partial_sum = sum / 3;
                sum = 0;
                int sub_array_count = 0;
                for(auto e: A){
                        sum += e;
                        if(sum == partial_sum && sub_array_count < 3){
                                sum = 0;
                                ++sub_array_count;
                        }
                }
                return sub_array_count == 3 && sum == 0;
        }
        int _1_sum(const vector<int>& A){
                int sum = 0;
                for(auto e: A)
                        sum += e;
                return sum;
        }

        /**
         * @brief err
         */
        bool _2(vector<int>& A){
                int zero_count = 0;
                unordered_set<int> us;
                int sum = 0;
                for(auto e: A){
                        sum += e;
                        if(sum == 0)
                                ++zero_count;
                        us.insert(sum);
                }
                if(sum == 0)
                        return zero_count >= 3;
                if(sum % 3 != 0)
                        return false;
                sum /= 3;
                //! err, sum should occur before sum*2
                if(us.find(sum) == us.end())
                        return false;
                if(us.find(sum * 2) == us.end())
                        return false;
                return true;
        }
};
