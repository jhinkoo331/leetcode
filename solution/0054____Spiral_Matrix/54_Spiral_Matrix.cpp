#include <vector>
using namespace std;

enum dir {dir_right, dir_down, dir_left, dir_up};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if(matrix.empty()){
			return ret;
		}
        pair<int, int> left_up = {0, 0};
		pair<int, int> right_bottom = {matrix.size() - 1, matrix.at(0).size() - 1};
		pair<int, int> cur_loc;
		dir cur_dir = dir_right;
		while(left_up.first <= right_bottom.first && left_up.second <= right_bottom.second){
			switch (cur_dir){
			case dir_right:
				cur_loc = left_up;
				while(cur_loc.second <= right_bottom.second){
					ret.push_back(matrix[cur_loc.first][cur_loc.second]);
					cur_loc.second++;
				}
				left_up.first++;
				cur_dir = dir_down;
				break;
			case dir_down:
				cur_loc = make_pair(left_up.first, right_bottom.second);
				while(cur_loc.first <= right_bottom.first){
					ret.push_back(matrix[cur_loc.first][cur_loc.second]);
					cur_loc.first++;
				}
				right_bottom.second--;
				cur_dir = dir_left;
				break;
			case dir_left:
				cur_loc = right_bottom;
				while(cur_loc.second >= left_up.second){
					ret.push_back(matrix[cur_loc.first][cur_loc.second]);
					cur_loc.second--;
				}
				right_bottom.first--;
				cur_dir = dir_up;
				break;
			case dir_up:
				cur_loc = make_pair(right_bottom.first, left_up.second);
				while(cur_loc.first >= left_up.first){
					ret.push_back(matrix[cur_loc.first][cur_loc.second]);
					cur_loc.first--;
				}
				left_up.second++;
				cur_dir = dir_right;
				break;
			default:
				break;
			}
		}
		return ret;
    }
};


int main(){
	vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<vector<int>> v2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<vector<int>> v3 = {};
	vector<vector<int>> v4 = {{1, 2, 3}};
	vector<vector<int>> v5 = {{}, {}, {}};
	Solution sln;
	sln.spiralOrder(v1);
	sln.spiralOrder(v2);
	sln.spiralOrder(v3);
	sln.spiralOrder(v4);
	sln.spiralOrder(v5);
	return 0;
}