#include <vector>
using std::vector;
#include <map>
using std::map;
#include <algorithm>
using std::max;

class Solution {
public:
        int findMaxLength(vector<int>& nums) {
                return _3(nums);
        }

private:
        /**
         * @brief 35, 27
         */
        int _1(vector<int>& nums){
                //* map<sum, index>
                map<int, int> m;
                int sum = 0;
                for(int i = 0; i < nums.size(); ++i){
                        sum += nums[i] ? 1 : -1;
                        m[sum] = i;
                }
                sum = 0;
                int max_len = m[0] == 0 ? 0 : m[0] + 1;
                for(int i = 0; i < nums.size(); ++i){
                        sum += nums[i] ? 1 : -1;
                        max_len = max(max_len, m[sum] - i);
                }
                return max_len;
        }
        /**
         * @brief 32, 29
         */
        int _2(vector<int>& nums){
                map<int, int> mp;
                mp[0] = -1;
                int max_len = 0;
                int sum = 0;
                for(int i = 0; i < nums.size(); ++i){
                        sum += nums[i] ? 1 : -1;
                        if(mp.find(sum) == mp.end())
                                mp[sum] = i;
                        else
                                max_len = max(max_len, i - mp[sum]);
                }
                return max_len;
        }
        /**
         * @brief 99, 97
         * 
         * @param nums 
         * @return int 
         */
        int _3(vector<int>& nums){
                vector<int> pos, neg;
                int sum = 0;
                int max_len = 0;
                for(int i = 0; i < nums.size(); ++i){
                        sum += nums[i] ? 1 : -1;
                        if(sum == 0)
                                max_len = i + 1;
                        else if(sum > 0)
                                if (sum > pos.size())
                                        pos.push_back(i);
                                else
                                        max_len = max(max_len, i - pos[sum - 1]);
                        else if(-sum > neg.size())
                                neg.push_back(i);
                        else
                                max_len = max(max_len, i - neg[-sum - 1]);
                }
                return max_len;
        }
};

int main(){
        vector<int> v = {0,0,1,0,0,0,1,1};
        Solution sln;
        sln.findMaxLength(v);
        return 0;
}
