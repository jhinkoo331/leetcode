#include "util\frequently_included.h"

class Solution {
public:
        int findUnsortedSubarray(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @brief sort and compare
         * @perf: 42, 7
         * @time: n*log_n
         * @space: n
         */
        int _1(vector<int>& nums){
                vector<int> temp = nums;
                sort(temp.begin(), temp.end());
                nums.push_back(1);      //* sentinel
                temp.push_back(0);
                //* left is the first different number from nums and temp
                int left = 0;
                while(left < nums.size() && nums[left] == temp[left])
                        ++left;
                if(left == nums.size() - 1)
                        return 0;
                int right = nums.size() - 2;
                while(nums[right] == temp[right])
                        --right;

                return right - left + 1;
        }

        int _2(vector<int>& nums){
                
        }
};

int main(){
        vector<int> v1 = {2,6,4,8,10,9,15};
        vector<int> v = {1, 2, 3, 4};
        Solution sln;
        sln.findUnsortedSubarray(v);
        return 0;
}