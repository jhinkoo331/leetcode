#include <vector>
#include <algorithm>
#include <unordered_set>
using std::sort;
using std::vector;


//NOTE: in LC judge system, `hash` is ambiguous.. you may change it into
// sth like `_hash` to avoid this err
struct hash{
        size_t operator() (const vector<int>& v) const{
                int ans = 0;
                for(const auto e: v)
                        ans ^= e;
                return ans;
        }
};


class Solution {
public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                return _1(candidates, target);
        }
private:
        vector<int> temp;
        int target;
        std::unordered_set<vector<int>, hash> us;
        vector<vector<int>> ans;
        /**
         * @brief 4ms, 55
         * @TODO: this code segment could be simplified
         * @param candidates 
         * @param target 
         * @return vector<vector<int>> 
         */
        vector<vector<int>> _1(vector<int>& candidates, int target){
                temp.clear();
                ans.clear();
                us.clear();
                this->target = target;
                std::sort(candidates.begin(), candidates.end());
                if(candidates.empty() && target == 0x7fffffff)
                        return ans;
                candidates.push_back(0x7fffffff);                       //! sentinel
                _11(candidates, 0);
                for(auto e: us)
                        ans.push_back(e);
                return ans;
        }
        void _11(const vector<int>& candidates, int index){
                bool go_on = true;
                while(go_on){
                        target -= candidates[index];
                        temp.push_back(candidates[index]);
                        if(target <= 0){
                                if(target == 0)
                                        us.insert(temp);
                                go_on = false;
                        }else  // target > 0
                                _11(candidates, index + 1);

                        target += candidates[index];
                        temp.pop_back();
                        ++index;
                }
        }
};

int main(){
        vector<int> v1 = {10,1,2,7,6,1,5};
        Solution sln;
        sln.combinationSum2(v1, 8);
        return 0;
}