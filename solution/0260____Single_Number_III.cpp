#include "util\frequently_included.h"

class Solution {
public:
        vector<int> singleNumber(vector<int>& nums) {
                return _1(nums);
        }
private:
        vector<int> _1(vector<int>& nums){
                int zero_count = 0;
                int temp = 0;
                for(int i = 0; i < nums.size(); ++i){
                        temp ^= nums[i];
                        if(nums[i] == 0)
                                ++zero_count;
                }
                if(zero_count == 1)
                        return vector<int>{0, temp};
                else
                        return _1_helper(nums, 0, nums.size());
        }
        vector<int> _1_helper(vector<int>& nums, int left, int right){
                int mid = left + (right - left) >> 1;
                int left_temp = 0;
                int right_temp = 0;
                for(int i = left; i < mid; ++i)
                        left_temp ^= nums[i];
                for(int i = mid; i < right; ++i)
                        right_temp ^= nums[i];
                if(left_temp != 0 && right_temp != 0)
                        return vector<int> {left_temp, right_temp};
                if(left_temp != 0)
                        return _1_helper(nums, left, mid);
                else
                        return _1_helper(nums, mid, right);
        }
        /**
         * @brief map used, restriction not satisfied
         * @perf: 22, 29
         */
        vector<int> _2(vector<int>& nums){
                map<int, int> m;
                for(auto e: nums)
                        ++m[e];
                vector<int> ans;
                for(auto e: m)
                        if(e.second == 1)
                                ans.push_back(e.first);
                return ans;
        }
        /**
         * @brief map used, restriction not satisfied
         * @perf: 52, 25
         */
        vector<int> _3(vector<int>& nums){
                unordered_set<int> us;
                for(auto e: nums)
                        if(us.find(e) != us.end())
                                us.erase(e);
                        else
                                us.insert(e);
                vector<int> ans;
                for(auto e: us)
                        ans.push_back(e);
                return ans;
        }
        /**
         * @brief sort the nums at first.
         * @perf: 47, 29
         */
        vector<int> _4(vector<int>& nums){
                vector<int> ans;
                sort(nums.begin(), nums.end());
                int i = 1;
                while(nums[i] == nums[i - 1])
                        i += 2;
                ans.push_back(nums[i - 1]);
                ++i;
                while(i < nums.size() && nums[i] == nums[i - 1])
                        i += 2;
                ans.push_back(nums[i - 1]);
                return ans;
        }
};

// TODO: the restriction of the problem