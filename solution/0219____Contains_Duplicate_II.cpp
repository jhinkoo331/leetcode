#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;


class Solution {
public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
                return _1(nums, k);
        }
private:
        /**
         * @perf: 96,53
         */
        bool _1(vector<int>& nums, int k){
                ++k;
                int left = 0, right = 0;
                unordered_set<int> us;
                int temp = nums.size() < k ? nums.size() : k;
                while(right < temp){
                        us.insert(nums[right++]);
                        if(us.size() != right)
                                return true;
                }
                while(right < nums.size()){
                        us.erase(nums[left++]);
                        us.insert(nums[right++]);
                        if(us.size() != k)
                                return true;
                }
                return false;
        }
        /**
         * @perf: 98, 61 
         */
        bool _2(vector<int>& nums, int k){
                ++k;
                int left = 0, right = 0;
                unordered_set<int> us;
                int temp = nums.size() < k ? nums.size() : k;
                while(right < temp)
                        if(!us.insert(nums[right++]).second)
                                return true;

                while(right < nums.size()){
                        us.erase(nums[left++]);
                        if(!us.insert(nums[right++]).second)
                                return true;
                }
                return false;
        }
};


int main(){
        vector<int> v = {1,2,3,1,2,3};
        Solution sln;
        sln.containsNearbyDuplicate(v, 2);
        return 0;
}