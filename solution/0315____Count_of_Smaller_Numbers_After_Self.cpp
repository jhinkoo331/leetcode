#include "util\frequently_included.h"

// todo: discuss, mergesort

class Solution {
public:
        vector<int> countSmaller(vector<int>& nums) {
                _1(nums);
                return nums;
        }
private:
        /**
         * @perf: 64, 5 
         */
        int offset;
        void _1(vector<int>& nums){
                offset = 1;
                while(offset < nums.size())
                        offset <<= 1;
                vector<int> tree(offset + nums.size(), 0);
                map<int, vector<int>> m;
                for(int i = 0; i < nums.size(); ++i)
                        m[nums[i]].push_back(i);
                for(auto itr = m.begin(); itr != m.end(); ++itr)
                        for(const auto index: itr->second){
                                nums[index] = count_of_bigger_numbers(tree, index);
                                add_bigger_number_count(tree, index);
                        }
        }
        /**
         * @brief 
         * 
         * @param tree 
         * @param index 
         * @return int count of numbers bigger than nums[index] right after nums[index]
         */
        int count_of_bigger_numbers(const vector<int>& tree, int index){
                int ans = 0;
                index += offset;
                while(index){
                        ans += tree[index];
                        index /= 2;
                }
                return ans;
        }
        void add_bigger_number_count(vector<int>& tree, int index){
                int cur_index = 1;
                for(int mask = offset >> 1; mask; mask >>= 1){
                        cur_index *= 2;
                        if(index & mask){
                                ++tree[cur_index];
                                ++cur_index;
                        }
                }
        }
};

int main(){
        vector<int> v = {4,3,2,0,1,0};
        Solution sln;
        sln.countSmaller(v);
        return 0;       
}
