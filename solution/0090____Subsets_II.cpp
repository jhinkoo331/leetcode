#include "util\frequently_included.h"

class Solution {
public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                _1(nums);
                return ans;
        }
private:
        vector<vector<int>> ans;
        vector<int> ans_temp;
        int nums_sz;
        /**
         * @brief dfs
         * @perf: 85, 14
         */
        void _1(vector<int>& nums){
                ans.clear();
                ans_temp.clear();
                if(nums.empty())
                        return;
                sort(nums.begin(), nums.end());
                nums_sz = nums.size();
                nums.push_back(nums.back() ^ 1);        //* sentinel
                _1_dfs(nums, 0);
        }
        void _1_dfs(vector<int>& nums, int index){
                int next_index = index + 1;
                while(nums[next_index] == nums[index])
                        ++next_index;
                //* search deeper
                if(next_index == nums_sz)
                        ans.push_back(ans_temp);
                else
                        _1_dfs(nums, next_index);
                for(int i = 0; i < next_index - index; ++i){
                        ans_temp.push_back(nums[index]);
                        if(next_index == nums_sz)
                                ans.push_back(ans_temp);
                        else
                                _1_dfs(nums, next_index);
                }
                //* restore the context
                for(int i = 0; i < next_index - index; ++i)
                        ans_temp.pop_back();
        }
};
