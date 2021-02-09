class Solution {
public:
        bool canCross(vector<int>& stones) {
                return _1(stones);
        }
        
private:
        // perf: 67, 39
        bool _1(vector<int>& stones) {
                if(stones[1] - stones[0] != 1)
                        return false;
                unordered_map<int, int> m;
                for(int i = 0; i < stones.size(); ++i)
                        m[stones[i]] = i;
                vector<unordered_set<int>> v(stones.size());
                v[1].insert(1);
                for(int i = 1; i < v.size(); ++i){
                        for(auto step: v[i]){
                                v[m[stones[i] + step]].insert(step);
                                v[m[stones[i] + step - 1]].insert(step - 1);
                                v[m[stones[i] + step + 1]].insert(step + 1);
                        }
                }
                return v.back().size();
        }
};