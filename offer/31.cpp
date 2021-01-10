#include "util\frequently_included.h"

class Solution {
public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
                return _1(pushed, popped);
        }
private:
        bool _1(vector<int>& pushed, vector<int>& popped){
                vector<vector<int>> v;
                pushed.push_back(-1);   // sentinel
                int pushed_index = 0;
                for(int i = 0; i < popped.size(); ++i){
                        bool found = false;
                        for(int ii = 0; ii < v.size(); ++ii)
                                if(v[ii].back() == popped[i]){
                                        v[ii].pop_back();
                                        if(v[ii].empty()){
                                                v[ii].swap(v.back());
                                                v.pop_back();
                                        }
                                        found = true;
                                        break;
                                }
                        if(found)
                                continue;
                        v.push_back(vector<int>());
                        pushed.back() = popped[i];      // sentinel
                        while(pushed[pushed_index] != popped[i])
                                v.back().push_back(pushed[pushed_index++]);
                        if(v.back().empty())
                                v.pop_back();
                        if(pushed_index == pushed.size() - 1)
                                return false;
                        ++pushed_index;
                }
                return v.empty() & pushed_index == pushed.size() - 1;
        }
        /**
         * @perf: 9, 87
         */
        bool _2(vector<int>& push, vector<int>& pop){
                if(push.size() != pop.size())
                        return false;
                stack<int> s;
                int push_index = 0;
                for(int i = 0; i < pop.size(); ++i){
                        if(s.size() && s.top() == pop[i]){
                                s.pop();
                                continue;
                        }
                        while(push_index < push.size() && push[push_index] != pop[i])
                                s.push(push[push_index++]);
                        if(push_index == push.size())
                                return false;
                        else
                                ++push_index;
                }
                return s.empty();
        }
};

int main(){
        vector<int> push = {8,2,1,4,7,9,0,3,5,6};
        vector<int> pop = {1,2,7,3,6,4,0,9,5,8};
        Solution sln;
        sln.validateStackSequences(push, pop);
        return 0;
}