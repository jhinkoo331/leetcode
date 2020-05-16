#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
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
			}else if(temp.first == grid.size() - 1){
				grid[temp.first][temp.second] += grid[temp.first][temp.second + 1];
			}else if(temp.second == grid.front().size() - 1){
				grid[temp.first][temp.second] += grid[temp.first + 1][temp.second];
			}else{
				grid[temp.first][temp.second] += grid[temp.first][temp.second + 1] < grid[temp.first + 1][temp.second] ? grid[temp.first][temp.second + 1] : grid[temp.first + 1][temp.second];
			}
			temp.first--;
			temp.second++;
		}

		// update loc
		if(loc.first == 0 && loc.second == 0){
			return false;
		}else{
			if(loc.second > 0){
				loc.second--;
			}else{
				loc.first--;
			}
			return true;
		}
	}
};


int main(){
	vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	Solution sln;
	sln.minPathSum(v);
	return 0;
}