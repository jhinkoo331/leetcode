#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



class Solution {
public:
	int hIndex(vector<int>& citations) {
		return hIndex_3(citations);
	}
private:
	//* perf: [26, 100]
	int hIndex_1(vector<int>& citations){
		sort(citations.begin(), citations.end(), greater<int>());
		for(int i = 0; i < citations.size(); ++i){
			if(citations[i] < i + 1){
				return i;
			}
		}
		return citations.size();
	}

	//* we use priority_queue rather than sorting all elements
	//* perf: [82, 100]
	int hIndex_2(vector<int>& citations){
		priority_queue<int> pq;
		for(const auto& elem: citations){
			pq.push(elem);
		}
		for(int i = 0; i < citations.size(); ++i){
			if(pq.top() < i + 1){
				return i;
			}
			pq.pop();
		}
		return citations.size();
	}

	//* make_heap in `citations`
	//* perf: [26, 88], much worse than hIndex_2
	int hIndex_3(vector<int>& citations){
		int sz = citations.size();
		make_heap(citations.begin(), citations.end());
		for(int i = 0; i < sz; ++i){
			if(citations[0] < i + 1){
				return i;
			}
			pop_heap(citations.begin(), citations.end());
			citations.pop_back();
		}
		return sz;
	}
};
