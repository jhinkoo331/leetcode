#include <vector>
using namespace std;

enum dir {dir_right, dir_down, dir_left, dir_up};

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> v;
		if(n <= 0){
			return v;
		}
		v.resize(n);
		for(auto& elem: v){
			elem.resize(n);
		}
		int area_up = 0, area_down = n - 1, area_left = 0, area_right = n - 1;
		int cur_row, cur_col;
		dir dir_cur = dir_right;			//* initial direction is from left to right
		int num_cur = 1;
		int n_n = n * n + 1;
		while(num_cur != n_n){
			switch (dir_cur){
			case dir_right:
				cur_row = area_up;
				cur_col = area_left;
				while(cur_col <= area_right){
					v[cur_row][cur_col] = num_cur;
					cur_col++;
					num_cur++;
				}
				area_up++;
				dir_cur = dir_down;
				break;
			case dir_down:
				cur_row = area_up;
				cur_col = area_right;
				while(cur_row <= area_down){
					v[cur_row][cur_col] = num_cur;
					cur_row++;
					num_cur++;
				}
				area_right--;
				dir_cur = dir_left;
				break;
			case dir_left:
				cur_row = area_down;
				cur_col = area_right;
				while(cur_col >= area_left){
					v[cur_row][cur_col] = num_cur;
					cur_col--;
					num_cur++;
				}
				area_down--;
				dir_cur = dir_up;
				break;
			case dir_up:
				cur_row = area_down;
				cur_col = area_left;
				while(cur_row >= area_up){
					v[cur_row][cur_col] = num_cur;
					cur_row--;
					num_cur++;
				}
				area_left++;
				dir_cur = dir_right;
				break;
			default:
				break;
			}
		}
		return v;
	}
};


int main(){
	Solution sln;
	sln.generateMatrix(-5);
	sln.generateMatrix(-1);
	sln.generateMatrix(0);
	sln.generateMatrix(1);
	sln.generateMatrix(5);
	sln.generateMatrix(0x80000000);			//* return empty vector
	sln.generateMatrix(0x7fffffff);			//* memory allocation failed
	return 0;
}