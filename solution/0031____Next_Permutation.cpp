#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
        void nextPermutation(vector<int>& nums){
                return _1(nums);
        }
private:
        /**
         * @brief 4ms, 61
         */
        void _1(vector<int>& nums) {
                if(nums.empty())
                        return;
                int index = nums.size() - 1;
                while(index - 1 >= 0 && nums[index - 1] >= nums[index])
                        --index;
                if(index == 0)
                        reverse(nums.begin(), nums.end());
                else
                        for(int i = nums.size() - 1; ; --i)
                                if(nums[i] > nums[index - 1]){
                                        int temp = nums[index - 1];
                                        nums[index - 1] = nums[i];
                                        nums[i] = temp;
                                        reverse(nums.begin() + index, nums.end());
                                        return;
                                }
        }
};


int main(){
        vector<int> v1 = {1, 2, 3};
        vector<int> v2 = {3, 2, 1};
        vector<int> v3 = {1, 1, 5};
        Solution sln;
        sln.nextPermutation(v1);
        sln.nextPermutation(v2);
        sln.nextPermutation(v3);
        return 0;
}

