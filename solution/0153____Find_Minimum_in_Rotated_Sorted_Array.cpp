#include <vector>
using std::vector;

class Solution {
public:
        int findMin(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @perf: [4ms, 18]
         * @time: O(log_n)
         * @space: constant
         */
        int _1(vector<int>& nums){
                int left = 0, right = nums.size() - 1;
                while(left < right - 1){	//TODO better edge test
                        if(nums[left] < nums[right])
                                break;
                        int mid = left + (right - left) / 2;
                        if(nums[left] >= nums[mid])
                                right = mid;
                        else
                                left = mid + 1;
                }
                return nums[left] < nums[right] ? nums[left] : nums[right];
        }
};

