#include "util\frequently_included.h"

class Solution {
public:
        int jump(vector<int>& nums) {
                return _2(nums);
        }
private:
        /**
         * @brief tle
         */
        int _1(vector<int>& nums){
                if(nums.empty())
                        return 0;
                nums.back() = 0;
                for(int i = nums.size() - 2; i >= 0; --i){
                        if(nums[i] == 0)
                                nums[i] = 0x7fffffff;
                        else{
                                int temp = i + nums[i] + 1 < nums.size() ? i + nums[i] + 1 : nums.size();
                                int min = *min_element(nums.begin() + i + 1, nums.begin() + temp);
                                if(min != 0x7fffffff)
                                        nums[i] = 1 + min;
                                else
                                        nums[i] = 0x7fffffff;
                        }
                }
                return nums.front();
        }
        /**
         * @brief bfs
         * @perf: 98, 43
         */
        int _2(vector<int>& nums){
                if(nums.size() < 2)
                        return 0;
                int step = 0;
                int left = 0, right = 0;		//* [left, right]
                while(true){
                        step++;			//* we take a step!
                        int new_right = 0;		//* the hightest stair we may reach in this step
                        for(int i = left; i <= right; ++i){
                                new_right = max(new_right, i + nums[i]);
                                if(new_right >= nums.size() - 1)		//* we have reach the top stair
                                        return step;
                        }
                        //* update [left, right]
                        left = right + 1;
                        right = new_right;
                }
                return -1;              //* make it compile. it's guaranteed you may always reach the top stair.
        }
};
