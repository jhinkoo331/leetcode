#include <vector>
using std::vector;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		return maxScore_1(cardPoints, k);
	}
private:
	/*
	 * perf: [40, 52]
	 * time: O(min(cardPoints.size(), 3k)) => O(min(n, k))
	 * space: O(1)
	 */
	int maxScore_1(vector<int>& cardPoints, int k){
		int ans = 0;
		if(k >= cardPoints.size()){
			for(auto e: cardPoints)
				ans += e;
			return ans;
		}
		for(int i = 0; i < k; ++i)
			ans += cardPoints[i];
		int max = ans;
		for(int i = 1; i <= k; ++i){
			ans -= cardPoints[k - i];
			ans += cardPoints[cardPoints.size() - i];
			max = max > ans ? max : ans;
		}
		return max;
	}
};
