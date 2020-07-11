#include <vector>
using std::vector;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		return _1(citations);
	}
private:
	/**
	 * @brief 
	 * @perf: [46, 60] 
	 * @param citations 
	 * @return int 
	 */
	int _1(vector<int>& citations){
		//* the result is not in range [ll, rr]
		if(citations.empty() || citations.back() == 0)
			return 0;
		//* the result is in range [ll, rr]
		int ll = 0, rr = citations.size() - 1;
		while(ll < rr){
			int mid = ll + (rr - ll) / 2;
			// if(citations[mid] == citations.size() - mid)
				// return citations.size() - mid;
			if(citations[mid] >= citations.size() - mid)
				rr = mid;
			else
				ll = mid + 1;
		}
		return citations.size() - ll;
	}
};
