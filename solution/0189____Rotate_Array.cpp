#include "util/frequently_included.h"

class Solution {
public:
        void rotate(vector<int>& nums, int k) {
                _2(nums, k);
        }
private:
        /**
         * @perf: [23, 96]
         * @time: O(n);
         * @space: in-place
         */
        void _1(vector<int>& nums, int k){
                if(nums.empty())
                        return;
                k %= nums.size();
                reverse(nums.begin(), nums.end() - k);
                reverse(nums.end() - k, nums.end());
                reverse(nums.begin(), nums.end());
                return;
        }
        /**
         * @brief TODO Approach 3: Using Cyclic Replacements
         * 
         */
        void _2(vector<int>& nums, int k){
                if(nums.empty())
                        return;
                k %= nums.size();
                for(int i = 0; i < k; ++i)
                        for(int ii = i + k; ii != i;){
                                int temp = nums[ii];
                                nums[ii] = nums[i];
                                nums[i] = temp;
                                ii += k;
                                ii %= nums.size();
                        }
        }
};

int main(){
        vector<int> v = {};
        vector<int> vv = {1};
        vector<int> vvv = {1,2,3,4,5,6,7,8,9,10,11,12};
        Solution sln;
        sln.rotate(v, 10);
        sln.rotate(vv, 18);
        sln.rotate(vvv, 0);
        // sln.rotate(vvv, 1);
        sln.rotate(vvv, 8);
        sln.rotate(vvv, 36);
        return 0;
}



