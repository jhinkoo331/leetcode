#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::priority_queue;
using std::pair;
using std::max;
using std::min;

class Solution {
public:
	int trap(vector<int>& height) {
		return trap_2(height);
	}
private:
	/**
	 * perf: [5, 7]
	 * Time: priority_queue: O(nlog(n)); update `ans`: O(n); total: O(n)
	 * Space: priority_queue: O(n)
	 */
	int trap_1(vector<int>& height){
		if(height.empty())
			return 0;
		//* pair<height, index>
		priority_queue<pair<int, int>> pq;
		for(int i = 0; i < height.size(); ++i)
			pq.push({height[i], i});
		int old_left = pq.top().second;
		int old_right = pq.top().second;
		int ans = 0;
		while(!pq.empty()){
			int temp = pq.top().first;
			int new_left = 0x7fffffff, new_right = -1;
			while(!pq.empty() && pq.top().first == temp){
				new_left = min(new_left, pq.top().second);
				new_right = max(new_right, pq.top().second);
				pq.pop();
			}
			for(int i = new_left; i < old_left; ++i)
				ans += temp - height[i];
			for(int i = new_right; i > old_right; --i)
				ans += temp - height[i];
			old_left = min(old_left, new_left);
			old_right = max(old_right, new_right);
		}
		return ans;
	}
	/**
	 * perf: [43, 35]
	 * Time: O(n): two-pass
	 * Space: O(1): constan extra space used
	 */
	int trap_2(vector<int>& height){
		if(height.empty())
			return 0;
		int heightest = 0;
		for(auto e: height)
			heightest = max(heightest, e);
		int cur_height;
		int ans = 0;

		cur_height = 0;
		int left = 0;
		while(height[left] != heightest){
			if(height[left] > cur_height)
				cur_height = height[left];
			else if(height[left] < cur_height)
				ans += cur_height - height[left];
			left++;
		}

		cur_height = 0;
		int right = height.size() - 1;
		while(height[right] != heightest){
			if(height[right] > cur_height)
				cur_height = height[right];
			else if(height[right] < cur_height)
				ans += cur_height - height[right];
			right--;
		}

		while(left != right){
			ans += heightest - height[left];
			left++;
		}
		return ans;
	}
};



int main(){
	vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution sln;
	sln.trap(v);
	return 0;
}
