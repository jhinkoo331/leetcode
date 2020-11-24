#include <vector>
using namespace std;

class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @time:       n
         * @space:      in-place
         * @perf:       78, 59
         */
        int _1(vector<int>& nums){
                if(nums.empty())
                        return 0;
                int next_free = 1;
                for(int i = 1; i < nums.size(); ++i)
                        if(nums[i - 1] != nums[i])
                                nums[next_free++] = nums[i];
                return next_free; 
        }
};
