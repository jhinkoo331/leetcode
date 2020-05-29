#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Int_cmp{
public:
	bool operator() (const int& i, const int& ii) const {
		return i > ii;
	}
};


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return findKthLargest_2(nums, k);
	}
private:
	//* priority_queue
	//* perf:[38, 7]
	int findKthLargest_1(vector<int>& nums, int k){
		priority_queue<int> pq;
		for(const auto& elem: nums){
			pq.push(elem);
		}
		for(int i = 1; i < k; ++i){
			pq.pop();
		}
		return pq.top();
	}

	//* set
	//* perf [31, 6]
	int findKthLargest_2(vector<int>& nums, int k){
		multiset<int, Int_cmp> ms;
		for(const auto& elem: nums){
			ms.insert(elem);
		}
		auto itr = ms.begin();
		for(int i = 1; i < k; ++i){
			++itr;
		}
		int i = *itr;
		return i;
	}

	//* partition
	int findKthLargest_3(vector<int>& nums, int k){
		int left = 0, right = nums.size();
		while(true){
			int pivot = nums[rand() % (right - left) + left];
			
		}
		return 0;
	}
};

int main(){
	vector<int> v = {3,2,3,1,2,4,5,5,6};
	Solution sln;
	int ret = sln.findKthLargest(v, 4);
	return 0;
}
