#include <vector>
using std::vector;


class Solution {
public:
        vector<int> productExceptSelf(vector<int>& nums) {
                return _1(nums);
        }
private:
        /**
         * @brief this method used division which is not allowed
         * @perf: 82, 80
         */
        vector<int> _1(vector<int>& nums){
                int total_product = 1;
                int zero_count = 0;
                for(auto num: nums)
                        if(num == 0)
                                ++zero_count;
                        else
                                total_product *= num;
                if(zero_count > 1)
                        for(auto& num: nums)
                                num = 0;
                else if(zero_count == 1)
                        for(auto& num: nums)
                                num = num == 0 ? total_product : 0;
                else
                        for(auto& num: nums)
                                num = total_product / num;
                return nums;
        }

        /**
         * @brief: all restrictions are satisfied
         * @perf: 82, 83
         * @time: n
         * @space: n
         */
        vector<int> _2(vector<int>& nums){
                if(nums.size() <= 1)
                        return nums;
                vector<int> right(nums.size());
                right.back() = nums.back();
                for(int i = right.size() - 2; i >= 0; --i)
                        right[i] = right[i + 1] * nums[i];
                vector<int>& left = nums;
                for(int i = 1; i < left.size(); ++i)
                        left[i] *= left[i - 1];
                right[0] = right[1];
                for(int i = 1; i < right.size() - 1; ++i)
                        right[i] = left[i - 1] * right[i + 1];
                right.back() = left[left.size() - 2];
                return right;
        }
        vector<int> _3(vector<int>& nums){
                //TODO: _2 could be enhanced
        }
};

int main(){
        vector<int> v1 = {1,2,3,4};
        Solution sln;
        sln.productExceptSelf(v1);
        return 0;
}