#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		for(int i = 1; i < prices.size(); ++i){
			if(prices[i - 1] < prices[i]){
				profit += prices[i] - prices[i - 1];
			}
		}
		return profit;
	}
};

int main(){
	Solution sln;
	vector<int> v1 = {};
	vector<int> v2 = {7, 1, 5, 3, 6, 4};
	vector<int> v3 = {1, 2, 3, 4, 5};
	vector<int> v4 = {7, 6, 4, 3, 1};
	sln.maxProfit(v1);
	sln.maxProfit(v2);
	sln.maxProfit(v3);
	sln.maxProfit(v4);
	return 0;
}