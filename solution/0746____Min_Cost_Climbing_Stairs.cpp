#include <vector>
#include <algorithm>
using std::min;
using std::vector;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) { 
		return _1(cost);
	}
public:
	int _1(vector<int>& cost){
		if(cost.empty())
			return 0;
		if(cost.size() == 1)
			return cost[0];
		for(int i = cost.size() - 3; i >= 0; --i)
			cost[i] += min(cost[i + 1], cost[i + 2]);
		return min(cost[0], cost[1]);
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v(4, 0);
	Solution sln;
	sln.minCostClimbingStairs(v);
	return 0;
}

