#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> max(prices.size());
		int cur_max = 0x80000000;			// INT32_MIN
		for(int i = prices.size() - 1; i >= 0; --i){
			cur_max = cur_max > prices[i] ? cur_max : prices[i];
			max[i] = cur_max;
		}
		int max_profit = 0;
		for(int i = 0; i < prices.size(); ++i){
			max_profit = max_profit > max[i] - prices[i] ? max_profit : max[i] - prices[i];
		}
		return max_profit;
	}
};


int main(){
	vector<int> price = {7, 1, 5, 3, 6, 4};
	Solution sln;
	sln.maxProfit(price);
	return 0;
}