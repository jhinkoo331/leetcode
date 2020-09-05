#include "util\frequently_included.h"

class Solution {
public:
        vector<vector<int>> subsets(vector<int>& nums) {
                _1(nums);
                return ans;
        }
private:
        vector<vector<int>> ans;
        /**
         * @perf: 23, 39
         */
        void _1(vector<int>& nums){
                ans.clear();
                ans.reserve(1 << nums.size());
                ans.push_back({});
                for(auto num: nums){
                        int sz = ans.size();
                        for(int i = 0; i < sz; ++i){
                                ans.push_back(ans[i]);
                                ans.back().push_back(num);
                        }
                }
        }
};

int main(){
        return 0;
}
