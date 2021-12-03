#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		for(int i = 0; i < grid.size(); ++i)
			for(int ii = 0; ii < grid.front().size(); ++ii)
				if(grid[i][ii] == '1'){
					count++;
					grid[i][ii] = 0;
					queue<pair<int, int>> q;
					q.push({i, ii});
					while(!q.empty()){
						pair<int, int> t = q.front();
						q.pop();
						if(t.first - 1 >= 0 && grid[t.first - 1][t.second] == '1'){
							grid[t.first - 1][t.second] = '0';
							q.push({t.first - 1, t.second});
						}
						if(t.second - 1 >= 0 && grid[t.first][t.second - 1] == '1'){
							grid[t.first][t.second - 1] = '0';
							q.push({t.first, t.second - 1});
						}
						if(t.first + 1 < grid.size() && grid[t.first + 1][t.second] == '1'){
							grid[t.first + 1][t.second] = '0';
							q.push({t.first + 1, t.second});
						}
						if(t.second + 1 < grid.front().size() && grid[t.first][t.second + 1] == '1'){
							grid[t.first][t.second + 1] = '0';
							q.push({t.first, t.second + 1});
						}
					}
                }
		return count;
	}
};

