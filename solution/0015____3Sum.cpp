#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#include "util\frequently_included.h"
using std::vector;
using std::unordered_map;

bool operator== (const vector<int>& lhs, const vector<int>& rhs){
        return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
}


class Solution {
public:
        vector<vector<int>> threeSum(vector<int> nums) {
                _5(nums);
                return ans;
        }
private:
        vector<vector<int>> _1(vector<int> nums){
                //* <value, count>
                unordered_map<int, int> um;
                vector<vector<int>> v;
                for(const auto e: nums)
                        um[e]++;
                for(int i = 0; i < nums.size(); ++i)
                        for(int ii = i + 1; ii < nums.size(); ++ii){
                                int target = -nums[i] - nums[ii];
                                int count = 1;
                                if(1);//TODO
                        }
                return v;
        }

        /**
         * @brief TLE, in situation like [0,0,0,0,....0]
         */
        vector<vector<int>> _2(vector<int>& nums){
                vector<vector<int>> v;					//* store the answer
                v.push_back(vector<int>());				//* insert a "singular" vector to the front
                std::sort(nums.begin(), nums.end());
                //* unordered_map<value, index>
                std::unordered_map<int, int> um;
                for(int i = 0; i < nums.size(); ++i)
                        um[nums[i]] = i;
                for(int i = 0; i < nums.size(); ++i)
                        for(int ii = i + 1; ii < nums.size(); ++ii){
                                int iii = um[- nums[i] - nums[ii]];
                                if(iii > ii && vector<int>{nums[i], nums[ii], nums[iii]} > v.back())
                                        v.push_back(vector<int>{nums[i], nums[ii], nums[iii]});
                        }
                v.erase(v.begin());
                return v;
        }
        /**
         * @brief updated from _2
         * @perf: [20, 16]
         */
        vector<vector<int>> _3(vector<int>& nums){
                vector<vector<int>> v;					//* store the answer
                std::sort(nums.begin(), nums.end());
                //* unordered_map<value, index>
                std::unordered_map<int, int> um;
                for(int i = 0; i < nums.size(); ++i)
                        um[nums[i]] = i;
                
                int sz = nums.size();
                //TODO what if all elements in nums are 0x80000000?
                nums.push_back(0x80000000);	//* to reduce edge tests
                for(int i = 0; i < sz;){
                        for(int ii = i + 1; ii < sz;){
                                int iii = um[- nums[i] - nums[ii]];
                                if(iii > ii)
                                        v.push_back(vector<int>{nums[i], nums[ii], nums[iii]});
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
         * @brief evolved from _3
         * @perf: 27, 53
         * @param nums 
         * @return vector<vector<int>> 
         */
        vector<vector<int>> v;					//* store the answer
        void _4(vector<int>& nums){
                std::sort(nums.begin(), nums.end());
                //* unordered_map<value, index>
                std::unordered_map<int, int> um;
                for(int i = 0; i < nums.size(); ++i)
                        um[nums[i]] = i;
                
                int sz = nums.size();
                nums.push_back(0x80000000);	//* to reduce edge tests
                for(int i = 0; i < sz;){
                        for(int ii = i + 1; ii < sz;){
                                if(um.find(- nums[i] - nums[ii]) != um.end()){
                                        //! compared with _3, um won't expand here
                                        int iii = um[- nums[i] - nums[ii]];
                                        if(iii > ii)
                                                v.push_back(vector<int>{nums[i], nums[ii], nums[iii]});
                                }
                                while(nums[ii + 1] == nums[ii])
                                        ++ii;
                                ++ii;
                        }
                        while(nums[i + 1] == nums[i])
                                ++i;
                        ++i;
                }
        }

        /**
         * @brief 
         * @perf: 85, 39
         */
        vector<vector<int>> ans;
        void _5(vector<int>& nums){
                std::sort(nums.begin(), nums.end());
                if(nums.empty() || nums.back() < 0 || nums.front() > 0)
                        return;
                int sz = nums.size();
                vector<int> v;
                int i = 0;
                nums.push_back(-1);             //* to reduce edge tests
                while(i < sz){
                        while(nums[i + 1] == nums[i])
                                ++i;
                        v.push_back(i);
                        ++i;
                }
                for(i = 0; i < sz - 2;){
                        int target = -nums[i] - nums[i + 1];
                        while(!v.empty() && nums[v.back()] > target)
                                v.pop_back();
                        if(v.empty() || v.back() <= i + 1)
                                break;
                        int iii = v.size() - 1;

                        for(int ii = i + 1; ii < sz - 1;){
                                target = -nums[i] - nums[ii];
                                while(iii >= 0 && nums[v[iii]] > target)
                                        --iii;
                                if(iii < 0 || v[iii] <= ii)
                                        break;
                                else if(nums[v[iii]] == target)
                                        ans.push_back(vector<int>{nums[i], nums[ii], nums[v[iii]]});
                                //* update ii
                                while(nums[ii + 1] == nums[ii])
                                        ++ii;
                                ++ii;
                        }
                        //* update i
                        while(nums[i + 1] == nums[i])
                                ++i;
                        ++i;
                }
        }

        /**
         * @brief evolved from _5, we removed the v in _5
         */
        void _6(vector<int>& nums){
                std::sort(nums.begin(), nums.end());
                if(nums.empty() || nums.back() < 0 || nums.front() > 0)
                        return;
                int sz = nums.size();
                int i = 0;
                nums.push_back(-1);             //* to reduce edge tests
                int iii = 
                for(i = 0; i < sz - 2;){
                        int target = -nums[i] - nums[i + 1];
                        while(!v.empty() && nums[v.back()] > target)
                                v.pop_back();
                        if(v.empty() || v.back() <= i + 1)
                                break;
                        int iii = v.size() - 1;

                        for(int ii = i + 1; ii < sz - 1;){
                                target = -nums[i] - nums[ii];
                                while(iii >= 0 && nums[v[iii]] > target)
                                        --iii;
                                if(iii < 0 || v[iii] <= ii)
                                        break;
                                else if(nums[v[iii]] == target)
                                        ans.push_back(vector<int>{nums[i], nums[ii], nums[v[iii]]});
                                //* update ii
                                while(nums[ii + 1] == nums[ii])
                                        ++ii;
                                ++ii;
                        }
                        //* update i
                        while(nums[i + 1] == nums[i])
                                ++i;
                        ++i;
                }

        }
};

int main(){
        vector<int> v1 = {0, 0};
        vector<int> v2 = {-1,0,1,2,-1,-4};
        vector<int> v3 = {0, 0};
        bool b = v1 == v3;
        Solution sln;
        sln.threeSum(v2);
        return 0;
}



