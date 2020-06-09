#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> profit = {0, 0};		//* profit[0] <= profit[1]
		int left = 0, right = 0;
		while(left < prices.size()){
			while(right + 1 < prices.size() && prices[right + 1] >= prices[right])
				right++;
			int temp = prices[right] - prices[left];
			if(temp > profit[1]){
				profit[0] = profit[1];
				profit[1] = temp;
			}else if(temp > profit[0]){
				profit[0] = temp;
			}
			right++;
			left = right;
		}
		return profit[0] + profit[1];
	}
};


int main(){
	vector<int> v1 = {1,2,4,2,5,7,2,4,9,0};
	vector<int> v2 = {1, 2, 3, 4, 5};
	vector<int> v3 = {7, 6, 4, 3, 1};
	vector<int> v4 = {};
	vector<int> v5 = {1};
	vector<int> v6 = {6, 1, 3, 2, 4, 7};
	Solution sln;
	sln.maxProfit(v6);
	sln.maxProfit(v1);
	sln.maxProfit(v2);
	sln.maxProfit(v3);
	sln.maxProfit(v4);
	sln.maxProfit(v5);
	return 0;
}