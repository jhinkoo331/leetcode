#include "util\frequently_included.h"

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return _3(nums, k);
	}
private:
	/**
	 * @brief priority queue
	 * @time: k*log_n + n*log_n
	 * @perf: 38, 7
	 */
	int _1(vector<int>& nums, int k){
		priority_queue<int> pq;
		for(const auto& elem: nums)
			pq.push(elem);
		for(int i = 1; i < k; ++i)
			pq.pop();
		return pq.top();
	}

	/**
	 * @brief set
	 * @perf: 31, 6
	 */
	int _2(vector<int>& nums, int k){
		multiset<int, std::greater<int>> ms;
		for(const auto& elem: nums)
			ms.insert(elem);
		auto itr = ms.begin();
		for(int i = 1; i < k; ++i)
			++itr;
		return *itr;
	}

	/**
	 * @brief use the algorithm from binary sort
	 * 
	 */
	int _3(vector<int>& nums, int k){
		int left = 0, right = nums.size();
		while(true){
			int pivot = nums[rand() % (right - left) + left];
			
		}
		return 0;
	}

	int _3_helper(vector<int>& nums, int left, int right){
		int pivot = nums[rand() % (right - left) + left];
	}
};


int arr[] = {1,10,1e2,1e3,1e4,1e5,1e6,1e7,1e8, 1e9};

inline int pow(int n){
	return arr[n];
}

int main(){
	vector<int> v = {3,2,3,1,2,4,5,5,6};
	Solution sln;
	int ret = sln.findKthLargest(v, 4);
	return 0;
}
