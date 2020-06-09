#include <vector>
// #include <tuple>
using std::vector;
using std::pair;


class Solution {
public:
	int maxArea(vector<int>& height) {
        
	}
private:
	int maxArea_1(vector<int>& height){
		//* <vector<pair<height, index>> right
		vector<pair<int, int>> right;
		//* the heightest we have meet
		int max_height = -1;
		int max_area = -1;
		for(int i = height.size() - 1; i != -1; --i){
			if(height[i] > max_height){
				right.push_back({height[i], i});
				max_height = height[i];
			}
		}
		max_height = -1;
		for(int i = 0; i < height.size(); ++i){
			if(height[i] > max_height){
				max_height = height[i];
				
			}
		}
	}
};