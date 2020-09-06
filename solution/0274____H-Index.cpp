#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



class Solution {
public:
	int hIndex(vector<int>& citations) {
		return _3(citations);
	}
private:
	/**
	 * @brief sort the array, n_log_n
	 * @perf:26, 100
	 */
	int hIndex_1(vector<int>& citations){
		sort(citations.begin(), citations.end(), greater<int>());
		for(int i = 0; i < citations.size(); ++i)
			if(citations[i] < i + 1)
				return i;
		return citations.size();
	}

	/**
	 * @brief 
	 * @perf: [82, 100]
	 */
	int hIndex_2(vector<int>& citations){
		priority_queue<int> pq;
		for(const auto& elem: citations)
			pq.push(elem);
		for(int i = 0; i < citations.size(); ++i){
			if(pq.top() < i + 1)
				return i;
			pq.pop();
		}
		return citations.size();
	}

	/**
	 * @perf: 4ms, 11
	 * @time: O(n)
	 * @space: O(n)
	 */
	int _3(vector<int>& citations){
		vector<int> v(citations.size() + 1);
		for(auto e: citations)
			if(e > citations.size())
				++v.back();
			else
				++v[e];
		int i = citations.size();
		int sum = 0;
		while(true){
			sum += v[i];
			if(sum >= i)
				return i;
			--i;
		}
	}
};
