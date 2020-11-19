#include "util\frequently_included.h"
class Solution {
public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
                _2(nums, ans, k);
                return ans;
        }
private:
        vector<int> ans;

        /**
         * @brief multi set
         * @perf: 9, 8
         */
        void _1(const vector<int>& nums, vector<int>& ans, const int k){
                int temp = nums.size() - k + 1;
                if(temp <= 0)
                        return;
                ans.reserve(temp);
                multiset<int> ms;
                for(int i = 0; i < k; ++i)
                        ms.insert(nums[i]);
                for(int i = 0; ; ++i){
                        ans.push_back(*(ms.rbegin()));
                        if(i + k == nums.size())
                                break;
                        ms.erase(ms.find(nums[i]));
                        ms.insert(nums[i + k]);
                }
                return;
        }
        /**
         * @brief monotone queue
         * @perf: 87, 93 
         */
        void _2(const vector<int>& nums, vector<int>& ans, const int k){
                ans.reserve(nums.size() - k + 1);
                // the queue is used to store indices the number of which are strictly decreasing
                deque<int> dq;
                for(int i = 0; i < k; ++i){
                        while(dq.size() && nums[dq.back()] <= nums[i])
                                dq.pop_back();
                        dq.push_back(i);
                }
                int i = k;
                while(true){
                        ans.push_back(nums[dq.front()]);
                        if(i == nums.size())
                                break;
                        while(dq.size() && nums[dq.back()] <= nums[i])
                                dq.pop_back();
                        dq.push_back(i);
                        if(dq.front() == i - k)
                                dq.pop_front();
                        ++i;
                }
                return;
        }
};


int main(){
        vector<int> v = {-7,-8,7,5,7,1,6,0};
        Solution sln;
        sln.maxSlidingWindow(v, 4);
        return 0;
}
