
#include "util\frequently_included.h"

bool cmp(vector<int>& lhs, vector<int>& rhs){
        if(lhs[0] < rhs[0])
                return true;
        if(lhs[0] > rhs[0])
                return false;
        if(lhs[1] < rhs[1])
                return true;
        return false;
}

inline bool operator<(const vector<int>& lhs, const vector<int>& rhs) {
        if(lhs[0] != rhs[0])
                return lhs[0] < rhs[0];
        else
                return lhs[1] < rhs[1];
}


class Solution {
public:
        int findMinArrowShots(vector<vector<int>>& points) {
                return _1(points);
        }
private:
        /**
         * @time: sort: nlog_n; re-arrange the vector: n; get final answer: n
         * @space: in-place
         * @perf: 100, 100
         */
        int _1(vector<vector<int>>& points){
                sort(points.begin(), points.end());

                int valid_points_count = 0;
                for(int i = 0; i < points.size(); ++i){
                        while(valid_points_count && points[valid_points_count - 1][1] >= points[i][1])
                                --valid_points_count;
                        points[valid_points_count] = points[i];
                        ++valid_points_count;
                }
                points.resize(valid_points_count);
                
                int count = 0;
                int i = 0;
                while(i < points.size()){
                        ++count;
                        int right_edge = points[i][1];
                        while(i < points.size() && points[i][0] <= right_edge)
                                ++i;
                }
                return count;
        }
};

int main(){
        vector<vector<int>> v = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
        Solution sln;
        sln.findMinArrowShots(v);
        return 0;
}


