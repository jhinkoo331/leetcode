#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct cmp{
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
		if(lhs.first != rhs.first)
			return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	}
};



class Solution {
public:
    int maxArea(vector<int>& height) {
		int max_water = 0x80000000;
		s.clear();
		this->check(height, 0, height.size() - 1, max_water);
		return max_water;
    }
private:
	set<pair<int, int>, cmp> s;
	void check(const vector<int>& height, int left, int right, int& max_water){
		if(left >= right || s.find(make_pair(left, right)) != s.end())
			return;
		s.insert(make_pair(left, right));
		max_water = max_water >	min(height[left], height[right]) * (right - left) ? max_water : min(height[left], height[right]) * (right - left);
		int temp = left;
		while(temp < height.size() && height[temp] <= height[left]) temp++;
		check(height, temp, right, max_water);
		temp = right;
		while(temp >= 0 && height[temp] <= height[right]) temp--;
		check(height, left, temp, max_water);
	}
};


int main(){
	vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	Solution sln;
	int ret = sln.maxArea(v);
	return 0;
}