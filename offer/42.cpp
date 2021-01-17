class Solution {
public:
        int maxSubArray(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @brief 99, 98
         */
        int _1(vector<int>& nums){
                int cur_sum = 0;
                int max_sum = 0x80000000;
                for(auto num: nums){
                        cur_sum += num;
                        max_sum = cur_sum > max_sum ? cur_sum : max_sum;
                        if(cur_sum < 0){
                                cur_sum = 0;
                                continue;
                        }
                }
                return max_sum;
        }
};