#include "util\frequently_included.h"

class Solution {
public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
                _1(nums);
                return nums;
        }
private:
        /**
         * @perf: 4ms, 99, 61
         * @time: nlog_n
         * @space: n
         */
        void _1(vector<int>& nums){
                // <number, index>
                vector<pair<int, int>> v;
                v.reserve(nums.size());
                for(int i = 0; i < nums.size(); ++i)
                        v.push_back({nums[i], i});
                sort(v.begin(), v.end());
                for(int i = 0; i < v.size(); /** omitted here */){
                        nums[v[i].second] = i;
                        int ii = i + 1;
                        for(; ii < v.size() && v[i].first == v[ii].first; ++ii)
                                nums[v[ii].second] = i;
                        i = ii;
                }
        }
};

int main(){
        vector<int> v = {8,1,2,2,3};
        Solution sln;
        sln.smallerNumbersThanCurrent(v);
        return 0;
}
