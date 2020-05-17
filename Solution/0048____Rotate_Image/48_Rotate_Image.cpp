#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() - 1;
		while(left < right){
			int times = right - left;
			for(int i = 0; i < times; ++i){
				int temp = matrix[left][left + i];
				matrix[left][left + i] = matrix[right - i][left];
				matrix[right - i][left] = matrix[right][right - i];
				matrix[right][right - i] = matrix[left + i][right];
				matrix[left + i][right] = temp;
			}
			left++;
			right--;
		}
		return;
    }
};


int main(){
	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<vector<int>> vv = {};
	vector<vector<int>> vvv = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
	Solution sln;
	sln.rotate(v);
	sln.rotate(vv);
	sln.rotate(vvv);
	return 0;
}