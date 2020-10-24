#include <vector>
using namespace std;

class Solution {
public:
        int minPathSum(vector<vector<int>>& grid) {
                return _1(grid);
                pair<int, int> loc = make_pair(grid.size() - 1, grid.front().size() - 1);
                while(this->process(grid, loc));
                return grid.front().front();
        }
private:
        bool process(vector<vector<int>>& grid, pair<int, int>& loc){
                pair<int, int> temp = loc;
                
                while(temp.first < grid.size() && temp.second < grid.front().size()){
                        if(temp.first == grid.size() - 1 && temp.second == grid.front().size() - 1){
                                //* the right-bottom cornor
                        }else if(temp.first == grid.size() - 1)
                                grid[temp.first][temp.second] += grid[temp.first][temp.second + 1];
                        else if(temp.second == grid.front().size() - 1)
                                grid[temp.first][temp.second] += grid[temp.first + 1][temp.second];
                        else
                                grid[temp.first][temp.second] += grid[temp.first][temp.second + 1] < grid[temp.first + 1][temp.second] ? grid[temp.first][temp.second + 1] : grid[temp.first + 1][temp.second];
                        temp.first--;
                        temp.second++;
                }

                // update loc
                if(loc.first == 0 && loc.second == 0)
                        return false;
                else{
                        if(loc.second > 0)
                                loc.second--;
                        else
                                loc.first--;
                        return true;
                }
        }
        /**
         * @brief dynamic programming
         * @perf: 99, 9
         */
        int _1(vector<vector<int>>& grid){
                if(grid.empty() || grid[0].empty())
                        return -1;      // err
                for(int i = 1; i < grid[0].size(); ++i)
                        grid[0][i] += grid[0][i - 1];
                for(int i = 1; i < grid.size(); ++i)
                        grid[i][0] += grid[i - 1][0];
                for(int row = 1; row < grid.size(); ++row)
                        for(int col = 1; col < grid[0].size(); ++col)
                                grid[row][col] += grid[row - 1][col] < grid[row][col - 1] ? grid[row - 1][col] : grid[row][col - 1];
                return grid[grid.size() - 1][grid[0].size() - 1];
        }
};


int main(){
        vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        Solution sln;
        sln.minPathSum(v);
        return 0;
}