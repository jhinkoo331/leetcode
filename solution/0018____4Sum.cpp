#include "util\frequently_included.h"

class Solution {
public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
                return _2(nums, target);
        }
private:
        /**
         * @brief 
         * @perf: [5, 5]
         */
        vector<vector<int>> _1(vector<int>& nums, int target){
                vector<vector<int>> v;
                if(nums.empty())
                        return v;
                std::sort(nums.begin(), nums.end());
                int sz = nums.size();
                std::unordered_map<int, int> um;                //* unordered_map<value, index>
                for(int i = 0; i < nums.size(); ++i)
                        um[nums[i]] = i;
                if(nums.back() < 0)                             //* reduce edge tests
                        nums.push_back(0);
                else
                        nums.push_back(-1);
                for(int i = 0; i < sz;){
                        for(int ii = i + 1; ii < sz;){
                                for(int iii = ii + 1; iii < sz;){
                                        int iiii = um[target - nums[i] - nums[ii] - nums[iii]];
                                        if(iiii > iii)
                                                v.push_back(vector<int>{nums[i], nums[ii], nums[iii], nums[iiii]});
                                        while(nums[iii + 1] == nums[iii])
                                                ++iii;
                                        ++iii;
                                }
                                while(nums[ii + 1] == nums[ii])
                                        ++ii;
                                ++ii;
                        }
                        while(nums[i + 1] == nums[i])
                                ++i;
                        ++i;
                }
                return v;
        }
        /**
         * @brief 
         * 
         * @param nums 
         * @param target 
         * @return vector<vector<int>> 
         */
        vector<vector<int>> _2(vector<int>& nums, int target){
                vector<vector<int>> v;
                if(nums.empty())
                        return v;
                std::sort(nums.begin(), nums.end());
                int sz = nums.size();
                std::unordered_map<int, int> um;                //* unordered_map<value, index>
                for(int i = 0; i < nums.size(); ++i)
                        um[nums[i]] = i;
                if(nums.back() < 0)                             //* reduce edge tests
                        nums.push_back(0);
                else
                        nums.push_back(-1);
                for(int i = 0; i < sz;){
                        for(int ii = i + 1; ii < sz;){
                                for(int iii = ii + 1; iii < sz;){
                                        int iiii = um[target - nums[i] - nums[ii] - nums[iii]];
                                        if(iiii > iii)
                                                v.push_back(vector<int>{nums[i], nums[ii], nums[iii], nums[iiii]});
                                        while(nums[iii + 1] == nums[iii])
                                                ++iii;
                                        ++iii;
                                }
                                while(nums[ii + 1] == nums[ii])
                                        ++ii;
                                ++ii;
                        }
                        while(nums[i + 1] == nums[i])
                                ++i;
                        ++i;
                }
                return v;
        }

        vector<vector<int>> _3(vector<int>& nums, int target){
                vector<vector<int>> ans;
                if(nums.size() < 4)
                        return ans;
                sort(nums.begin(), nums.end());
                unordered_map<int, int> um;
                for(int i = 0; i < nums.size(); ++i)
                        for(int ii = i + 1; ii < nums.size(); ++ii)
                                um[nums[i] + nums[ii]] = i;
                int sz = nums.size();
                nums.push_back(nums.back() ^ 1);        //* sentinel
                for(int i = 0; i < sz; ++i){
                        for(int ii = i + 1; ii < sz; ++ii){
                                int implement = target - nums[i] - nums[ii];
                                auto itr = um.find(implement);
                                if(itr != um.end() && itr->second > ii)
                                        ans.push_back({nums[i], nums[ii], nums[itr->second], target - nums[i] - nums[ii] - nums[itr->second]});
                                while(nums[ii] == nums[ii + 1])
                                        ++ii;
                        }
                        while(nums[i] == nums[i + 1])
                                ++i;
                }
                return ans;
        }
};
