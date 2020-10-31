#include "util\frequently_included.h"

class Solution {
public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                _1(nums1, nums2);
                return nums1;
        }
private:
        /**
         * @brief store the ans into nums1
         * @perf: 95, 8
         */
        void _1(vector<int>& nums1, vector<int>& nums2){
                // unordered_map<number in nums1, index of the number>
                unordered_map<int, int> um;
                for(int i = 0; i < nums1.size(); ++i)
                        um[nums1[i]] = i;
                stack<int> s;           // elements in the stack is decreasing
                for(int i = nums2.size() - 1; i >= 0; --i){
                        int num = nums2[i];
                        while(s.size() && s.top() <= num)
                                s.pop();
                        auto itr = um.find(num);
                        if(itr != um.end())
                                if(s.size())
                                        nums1[itr->second] = s.top();
                                else
                                        nums1[itr->second] = -1;
                        s.push(num);
                }
        }
};
