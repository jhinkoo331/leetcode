#include "util\frequently_included.h"

class Solution {
public:
        vector<int> sortArray(vector<int>& nums) {
                // return bubble_sort(nums);
                return std_sort(nums);
        }
private:
        /**
         * @perf: tle
         * @time: n^2
         * @space: in-place
         */
        vector<int> bubble_sort(vector<int>& nums){
                for(int i = 0; i < nums.size(); ++i)
                        for(int ii = i + 1; ii < nums.size(); ++ii)
                                if(nums[i] > nums[ii]){
                                        int temp = nums[i];
                                        nums[i] = nums[ii];
                                        nums[ii] = temp;
                                }
                return nums;
        }
        /**
         * @perf: 59, 98
         */
        vector<int> std_sort(vector<int>& nums){
                sort(nums.begin(), nums.end());
                return nums;
        }
};
