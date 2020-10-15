#include "util\frequently_included.h"

class Solution {
public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
                return _1(nums1, nums2);
        }
private:
        /**
         * @perf: 69, 73
         * @time: linear
         * @space: linear
         */
        vector<int> _1(vector<int>& nums1, vector<int>& nums2) {
                unordered_set<int> s1, ans;
                for(auto e: nums1)
                        s1.insert(e);
                for(auto e: nums2)
                        if(s1.find(e) != s1.end())
                                ans.insert(e);
                vector<int> ans_v;
                for(auto e: ans)
                        ans_v.push_back(e);
                return ans_v;
        }
};
