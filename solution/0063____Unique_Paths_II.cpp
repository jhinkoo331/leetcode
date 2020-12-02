#include "util\frequently_included.h"

class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                return _1(obstacleGrid);
        }
private:
        /**
         * @brief 
         * @perf: 92, 72
         * @param grid spaces are marked as 0
         * @return int 
         */
        int _1(vector<vector<int>>& grid){
                _1_process_first_row(grid[0]);
                for(int row = 1; row < grid.size(); ++row){
                        if(grid[row][0] == 0)
                                grid[row][0] = grid[row - 1][0];
                        else
                                grid[row][0] = 0;
                        for(int col = 1; col < grid[row].size(); ++col)
                                if(grid[row][col] == 0)
                                        grid[row][col] = grid[row - 1][col] + grid[row][col - 1];
                                else
                                        grid[row][col] = 0;
                }
                return grid.back().back();
        }
        void _1_process_first_row(vector<int>& v){
                int i = 0;
                while(i < v.size())
                        if(v[i] == 0){
                                v[i] = 1;
                                ++i;
                        }
                        else
                                break;
                while(i < v.size()){
                        v[i] = 0;
                        ++i;
                }
        }
};

int main(){
        vector<vector<int>> v = {{1}, {0}};
        Solution sln;
        sln.uniquePathsWithObstacles(v);
        return 0;
}
