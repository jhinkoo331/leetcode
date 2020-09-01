#include "util\frequently_included.h"

class Solution {
public:
        int threeSumClosest(vector<int>& nums, int target) {
                return _1(nums, target);
        }
private:
        /**
         * @brief TODO
         * @perf: 5, 5
         */
        int _1(vector<int>& nums, int target){
                //* map<i, index> means that: number i's last appears at position index
                map<int, int> m;
                int diff = 0x7fffffff;
                int ans;
                // sort(nums.begin(), nums.end());
                for(int i = 0; i < nums.size(); ++i)
                        m[nums[i]] = i;
                for(int i = 0; i < nums.size(); ++i)
                        for(int ii = i + 1; ii < nums.size(); ++ii){
                                int t_target = target - nums[i] - nums[ii];
                                m.emplace(t_target, 0);
                                auto itr = m.find(t_target);
                                map<int, int>::reverse_iterator r_itr(itr);
                                while(itr != m.end() && itr->first - t_target < diff){
                                        if(itr->second > ii){
                                                diff = itr->first - t_target;
                                                ans = nums[i] + nums[ii] + itr->first;
                                        }
                                        ++itr;
                                }
                                while(r_itr != m.rend() && t_target - r_itr->first < diff){
                                        if(r_itr->second > ii){
                                                diff = t_target - r_itr->first;
                                                ans = nums[i] + nums[ii] + r_itr->first;
                                        }
                                        ++r_itr;
                                }
                                if(diff == 0)
                                        break;
                        }
                return ans;
        }
};

int main(){
        vector<int> v1 = {-1, 2, 1, -4};
        Solution sln;
        sln.threeSumClosest(v1, 1);
        return 0;
}

